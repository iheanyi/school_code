/* Iheanyi Ekechukwu

Project I

System Calls and Copying
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

// Define function prototypes
void handler(int s);
void display_message(int s); 


int main(int argc, char* argv[]) {

	// Initialize signals
	signal(SIGALRM, display_message);
	signal(SIGINT, display_message);


	/* Argument Size Checking*/
	if(argc != 3) {
		if(argc < 3) {
			printf("copyit: Too few arguments!\n");
		}
		else {
			printf("copyit: Too many arguments!\n");
		}
		printf("usage: copyit <sourcefile> <targetfile>\n");
		exit(1);
	}

	/* Define Variables */

	int sourcefp = open(argv[1], O_RDONLY); // Opening of source file

	// Error handling for source file
	if(sourcefp == -1) {
		printf("Couldn't open file %s: %s\n", argv[1], strerror(errno));
		exit(1);
	}

	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; // Unsure of who will be handling this file
																			 // so all permissions are activated

	int targetfp = creat(argv[2], mode); // Let's create a new file, if it already exists, it will be overwritten

	// Error handling for target file
	if(targetfp == -1) {
		printf("Couldn't write to file %s: %s\n", argv[2], strerror(errno));
		exit(1);
	}

	size_t totalBytes = 0; // Counting the number of bytes transferred

	// Lets set up a buffer for the characters we'll be copying from the file
	char buffer[400];

	ssize_t rddata; // Data being read from the source file
	ssize_t wrdata; // Data being written to the target file


	// Initialize alarm for every second
	alarm(1);

	// You want to loop while continually updating the file
	while((rddata = read(sourcefp, buffer, 200))) {
		// Error Handling
		if(rddata < 0) {
			printf("Error reading from file %s: %s\n", argv[1], strerror(errno));
			exit(1);		
		}


		// Write to target file and increase the total dbytes written to the file
		wrdata = write(targetfp, buffer, rddata);

		if(wrdata != rddata) {
			printf("Error: Not all data was copied. Terminating . . . \n");
			exit(1);
		}
		// Error handling
		if(wrdata < 0) {
			printf("Error writing to file %s: %s\n", argv[2], strerror(errno));
			exit(1);
		}

		totalBytes += rddata; // Increase total size of files being copied

		//printf("%s", strerror(errno));
		if(errno > 0) {
			printf("%s", strerror(errno));

		
		}
	}
	close(sourcefp);
	close(targetfp);

	printf("%zd bytes from file '%s' successfully copied to file '%s'\n", totalBytes, argv[1], argv[2]);


	return 0;
}

// Displays messages, overrides the default messages so that the copying still occurs and whatnot.
void display_message(int s) {

	// Case statement for signal alarms, signal interruptions
	switch(s) {
		case SIGALRM:
			printf("copyit: still copying...\n");
			signal(SIGALRM, display_message);
			alarm(1);
			break;
		case SIGINT:
			signal(SIGINT, display_message);
			break;
		default:
			break;
	}

}