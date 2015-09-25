/*
 *Justin Bartlett
 *Iheanyi Ekechukwu
 *Project 5
Main program for the virtual memory project.
Make all of your modifications to this file.
You may add or rearrange any code or data as you need.
The header files page_table.h and disk.h explain
how to use the page table and disk interfaces.
*/

#include "page_table.h"
#include "program.h"
#include "disk.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#define DEBUG 0

//used in page fault handler to determine what type of replacement to do
char* policyType;

//used to track statistics to print at the end
int pageFaults = 0;
int diskReads = 0;
int diskWrites = 0;

//must be global because used in page fault handler
char* virtmem = NULL;
char* physmem = NULL;
struct disk* disk = NULL;

//each entry of the frametable is one of these structs
typedef struct
{
	int page;
	int bits;
} frameEntry;

//must be declared global because used in replacement
frameEntry* frameTable = NULL;

//for fifo
int front=0;
int rear=0;
int *fifoArray;

//used in handlers so must be global, track the number of pages and frames
int npages;
int nframes;

//helper functions for the handlers to use to remove a page and check for a free frame
void remove_page(struct page_table *pt, int frameNumber);
int check_free_frame();

//handler for page faults for each policy
void rand_fault_handler(struct page_table *pt, int page);
void fifo_fault_handler(struct page_table *pt, int page);
void custom_fault_handler(struct page_table *pt, int page);
void custom2_fault_handler(struct page_table *pt, int page);


//general case handler to handle all page faults, selects the method to use based on the policy
void page_fault_handler( struct page_table *pt, int page )
{
	//increment number of page faults every fault
	pageFaults++;
	//select the policy to use
	if(!strcmp(policyType,"rand"))
	{
		rand_fault_handler(pt, page);
	}
	else if(!strcmp(policyType,"fifo"))
	{
		fifo_fault_handler(pt, page);
	}
	else if(!strcmp(policyType, "custom"))
	{
		custom_fault_handler(pt, page);
	} else if(!strcmp(policyType, "custom2"))
	{
		custom2_fault_handler(pt, page);
	}
	else //check for incorrect policy name
	{
		printf("use: virtmem <npages> <nframes> <rand|fifo|custom> <sort|scan|focus>\n");
		exit(1);
	}
}

int main( int argc, char *argv[] )
{
	//seed for random page replacement
	//srand48(time(NULL));
	
	//ensure correct number of arguments passed
	if(argc!=5)
	{
		printf("use: virtmem <npages> <nframes> <rand|fifo|custom> <sort|scan|focus>\n");
		return 1;
	}

	//set variables based on user input
	npages = atoi(argv[1]);
	nframes = atoi(argv[2]);
	policyType = argv[3];
	const char *program = argv[4];
	
	//create disk and page table
	disk = disk_open("myvirtualdisk",npages);
	if(!disk)
	{
		fprintf(stderr,"couldn't create virtual disk: %s\n",strerror(errno));
		return 1;
	}
	struct page_table *pt = page_table_create( npages, nframes, page_fault_handler );
	if(!pt)
	{
		fprintf(stderr,"couldn't create page table: %s\n",strerror(errno));
		return 1;
	}

	//create fifo array based on the number of frames
	fifoArray = malloc (nframes * sizeof(int));
	
	//create the frame table and check to make sure allocated correctly
	frameTable = malloc(nframes * sizeof(frameEntry));
	if (frameTable == NULL)
	{
	    printf("Error allocating space for frame table!\n");
	    exit(1);
	}

	//set virtual and physical memory
	virtmem = page_table_get_virtmem(pt);
	physmem = page_table_get_physmem(pt);

	//select the program to run based on user input
	if(!strcmp(program,"sort"))
	{
		sort_program(virtmem,npages*PAGE_SIZE);
	}
	else if(!strcmp(program,"scan"))
	{
		scan_program(virtmem,npages*PAGE_SIZE);
	}
	else if(!strcmp(program,"focus"))
	{
		focus_program(virtmem,npages*PAGE_SIZE);
	}
	else
	{
		fprintf(stderr,"unknown program: %s\n",argv[4]);
		printf("use: virtmem <npages> <nframes> <rand|fifo|custom> <sort|scan|focus>\n");
		exit(1);
	}

	//clean up
	free(frameTable);
	free(fifoArray);
	page_table_delete(pt);
	disk_close(disk);
	
	//print results to user
	printf("Disk Reads: %d\n", diskReads);
	printf("Disk Writes: %d\n", diskWrites);
	printf("Page Faults: %d\n", pageFaults);

	return 0;
}

////////////////////////
//Page Fault Handlers//
///////////////////////

//Random page fault handler
void rand_fault_handler(struct page_table *pt, int page)
{
	//get the current frame and bits
	int frame, bits;
	page_table_get_entry(pt, page, &frame, &bits);

	// fIndex used to track the frame
	int fIndex;

	//if the a bit is not set it is not in the page table
	if(!bits)
	{ 
		//set bits to protected read
		bits = PROT_READ;
		
		//check for a free frame, returns -1 if there is not a free frame
		fIndex = check_free_frame();

		//if there is NOT a free frame find a random frame index
		if(fIndex < 0)
		{
			//randomly select a frame and remove that page
			fIndex = (int) lrand48() % nframes;
			remove_page(pt, fIndex);
		}
		//read from disk into the selected frame and increment disk reads
		disk_read(disk, page, &physmem[fIndex*PAGE_SIZE]);
		diskReads++;

	}
	//if bits are prot_read set it so that it is dirty
	else if(bits & PROT_READ)
	{
		//give write priveledges and set fIndex to the frame returned as it will write to the same frame
		bits = PROT_READ | PROT_WRITE;
		fIndex = frame;
	} 
	else //catch any errors, should never get in here
	{
		printf("Error on random page fault.\n");
		exit(1);
	}

	//Update page table
	page_table_set_entry(pt, page, fIndex, bits);

	//Update frame table used to track
	frameTable[fIndex].page = page;
	frameTable[fIndex].bits = bits;

	if (DEBUG) {page_table_print(pt); printf("\n\n");}
}

//First in, first out page fault handler, swap the frame that came in first
void fifo_fault_handler(struct page_table *pt, int page)
{
	//get the current frame and bits
	int frame, bits;
	page_table_get_entry(pt, page, &frame, &bits);

	// fIndex used to track the frame
	int fIndex;
	
	// if the bit is not set, read it into the page table
	if(!bits)
	{ 
		//set bits to PROT_READ
		bits = PROT_READ;
		
		//check for a free frame, returns -1 if there is not one
		fIndex = check_free_frame();

		//if there is not a free fame swap out the one the came in first
		if(fIndex < 0)
		{
			//ensure that "front" pointer of queue = "back" pointer (ie queue is full) (this check should not be needed but in either case is here for protection)
			if (front==rear)
			{
				//select the frame index as the front of the array, and remove that page
				fIndex = fifoArray[front];
				remove_page(pt, fIndex);
			}
			else //catch any errors, should never enter here
			{
				printf("ERROR: on FIFO page swap\n");
				exit(1);
			}
		}
		//read from the disk and increment disk reads
		disk_read(disk, page, &physmem[fIndex*PAGE_SIZE]);
		diskReads++;
		//update the rear pointer of the array
		fifoArray[rear]=fIndex;
		rear =(rear +1) % nframes;

	}
	//if bits are prot_read set it so that it is dirty
	else if(bits & PROT_READ)
	{
		//give write priveledges and set fIndex to the frame returned as it will write to the same frame
		bits = PROT_READ | PROT_WRITE;
		fIndex = frame;
	} 
	else //catch any errors, should never get in here
	{
		printf("Error on random page fault.\n");
		exit(1);
	}

	//Update page table;
	page_table_set_entry(pt, page, fIndex, bits);

	//Update frame table used to track
	frameTable[fIndex].page = page;
	frameTable[fIndex].bits = bits;

	if (DEBUG) {page_table_print(pt); printf("\n\n");}	

}

//SECOND CHANCE RAND (100 extra chances..)
void custom2_fault_handler(struct page_table *pt, int page)
{
	//Random page fault handler
	int frame, bits;
	page_table_get_entry(pt, page, &frame, &bits);

	// fIndex tracks the frame index
	int fIndex;

	//if the a bit is not set it is not in the page table
	if(!bits)
	{ 
		//set bits to protected read
		bits = PROT_READ;
		
		//check for a free frame, returns -1 if there is not a free frame
		fIndex = check_free_frame();

		//if there is NOT a free frame find a random frame index
		if(fIndex < 0)
		{
			//randomly select a frame and remove that page
			fIndex = (int) lrand48() % nframes;
			
			int i=0;
			while (i<100)
			{
				if(frameTable[fIndex].bits & PROT_WRITE)
				{
					fIndex = ((int) lrand48())% nframes;
					//printf("test%i\n",i);
				}
				i++;
			}
			remove_page(pt, fIndex);
		}
		//read from disk into the selected frame and increment disk reads
		disk_read(disk, page, &physmem[fIndex*PAGE_SIZE]);
		diskReads++;

	}
	//if is already in there are prot_read, add dirty bit
	else if(bits & PROT_READ)
	{
		//give write priveledges and set fIndex to the frame returned
		bits = PROT_READ | PROT_WRITE;
		fIndex = frame;
	} 
	else //catch any errors, should never enter here
	{
		printf("Error on random page fault.\n");
		exit(1);
	}

	//Update page table;
	page_table_set_entry(pt, page, fIndex, bits);

	//Update frame table
	frameTable[fIndex].page = page;
	frameTable[fIndex].bits = bits;

}

//SECOND CHANCE FIFO
void custom_fault_handler(struct page_table *pt, int page)
{
	//Second chance FIFO
	int frame, bits;
	page_table_get_entry(pt, page, &frame, &bits);

	// fIndex tracks the frame index
	int fIndex;
	
	// if the bit is not set, read it into the page table
	if(!bits)
	{ 	
		//set bits to PROT_READ
		bits = PROT_READ;
		//check for a free frame, returns -1 if there is not one
		fIndex = check_free_frame();

		//if there is not a free fame swap out the one the came in first
		if(fIndex < 0)
		{
			//ensure that "front" pointer of queue = "back" pointer (ie queue is full)
			if (front==rear)
			{
				fIndex = fifoArray[front];
				//check if it is written
				//int temp=0;
				int i=0;
				while (i<2)
				{
					if(frameTable[fIndex].bits & PROT_WRITE)
					{
						front = (front+1)%nframes;
						rear = (rear+1)%nframes;
						fIndex = fifoArray[front];
					}
					i++;
				}

				remove_page(pt, fIndex);
			}
			else //catch any errors
			{
				printf("ERROR");
				exit(1);
			}
		}
		//read from the disk 
		disk_read(disk, page, &physmem[fIndex*PAGE_SIZE]);
		diskReads++;
		//update the rear pointer of the array
		fifoArray[rear]=fIndex;
		rear =(rear +1) % nframes;

	}
	else if(bits & PROT_READ)
	{
		bits = PROT_READ | PROT_WRITE;
		fIndex = frame;
	} 
	else
	{
		printf("Error on random page fault.\n");
		exit(1);
	}

	//Update page table;
	page_table_set_entry(pt, page, fIndex, bits);

	//Update frame table
	frameTable[fIndex].page = page;
	frameTable[fIndex].bits = bits;

	if (DEBUG) {page_table_print(pt); printf("\n\n");}	

}

//if there are any unmarked bits, return a free frame (will only happen until all frames are read in then will always return -1)
int check_free_frame()
{
	int i;
	for(i = 0; i < nframes; i++)
	{
		if(frameTable[i].bits == 0)
			return i;
	}
	return -1;
}

//remove a page
void remove_page(struct page_table *pt, int frameNumber)
{
	//if there is a dirty bit then write back to disk
	if(frameTable[frameNumber].bits & PROT_WRITE)
	{
		disk_write(disk, frameTable[frameNumber].page, &physmem[frameNumber*PAGE_SIZE]);
		diskWrites++;
	}
	//set the entry to not be writen; update the frame table to represent that and update the front "pointer"
	page_table_set_entry(pt, frameTable[frameNumber].page, frameNumber, 0);
	frameTable[frameNumber].bits = 0;
	front=(front+1)%nframes;

}
