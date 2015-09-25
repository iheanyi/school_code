/* Travel.c

Objective of this program is to make a travel database to make an itinerary for a person flying

Coded by Iheanyi Ekechukwu */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

// Flight Structure Definition
struct fl {
 char origin[4];
 char dest[4];
 int atime_h;
 int atime_m;
 int dtime_h;
 int dtime_m;
 int price;
};

// Function Prototypes
void fill_array(struct fl* flight);
void first_flight(char* origin, struct fl* flight);
void find_flights(char* origin, struct fl* flight);
int choose_flight(char* origin, int hour, int min, struct fl* flight);
void plan_itinerary(char* origin, struct fl* flight, int* itinerary, char* answer);
void write_itinerary(int* itinerary, struct fl* flight, int price);
void getResponse(char* answer);
int checkOrigin(char* origin);

// Main function
int main (void) {
  // Declare variables
  
struct fl flight[MAX];
char origin[10];
int itinerary[MAX] = {1};
char answer[MAX];

fill_array(flight);

first_flight(origin, flight);

plan_itinerary(origin, flight, itinerary, answer);

return 0;
}

// Custom functions

// Fill flight structure with data from the txt file.
void fill_array(struct fl* flight) {
int i = 0;
char line[MAX];

FILE* flightPtr;

flightPtr = fopen("flights.txt","r");
if(!flightPtr) { /* handle error */ }

else {
while(fgets(line, sizeof(line), flightPtr)) {
  sscanf(line, "%s %s %d:%d %d:%d $%d", flight[i].origin, flight[i].dest, &flight[i].atime_h, &flight[i].atime_m, &flight[i].dtime_h, &flight[i].dtime_m, &flight[i].price);
  i++;
}
}
fclose(flightPtr);
 
}

// Function for declaring the beginning point.
void first_flight(char* origin, struct fl* flight) {
  int valid;
 while(1) {
 printf("Enter your starting airport:");
 scanf("%s", origin);
 
 valid = checkOrigin(origin);
 
 if(valid == 1) {
  break; 
 }
 
}
}

// List all of the possible flights from the user's location
void find_flights(char* origin, struct fl* flight) {
  int i;
  int matchNum = 0;
  // Find the input and display all of its results
 printf("Here are all the flights from your desired location:\n");
 
 for(i = 0; i < 100; i++) {
  if(strcmp(flight[i].origin, origin) == 0) {
  printf("%d %s %s %d:%02d %d:%02d $%d\n", i, flight[i].origin, flight[i].dest, flight[i].atime_h, flight[i].atime_m, flight[i].dtime_h, flight[i].dtime_m, flight[i].price);
  matchNum++;
  }
 }

}

// Allows the user to choose which flight they want to take.
int choose_flight(char* origin, int hour, int min, struct fl* flight) {
 int num;
 int new_h = 0;
 int new_m = 0;
 find_flights(origin, flight);
 
 while(1) {
   
 printf("Please enter the number of the later flight that you want to take:");
 scanf("%d", &num);
 
 if(strcmp(num, "cancel") == 0) {
   
   return 1;
   
 }
 
 new_h = flight[num].dtime_h;
 new_m = flight[num].dtime_m;
 
 if((new_h > hour) || ((new_h == hour) && (new_m > min))) break;
 
 }
 
 return num;
 
}

// Plans the itinerary, writing the data to the itinerary array.
void plan_itinerary(char* origin, struct fl* flight, int* itinerary, char* answer) {
int i = 0;
int n;
int hour = 0;
int min = 0;
int cost = 0;

while(1) {
  
  n = choose_flight(origin, hour, min, flight);
  itinerary[i] = n;
  strcpy(origin, flight[n].dest);
  hour = flight[n].dtime_h;
  min = flight[n].dtime_m;
  cost += flight[n].price;
  getResponse(answer);
  
  if(strcmp(answer, "cancel") == 0) {
     if(i == 1) {
      strcpy(origin, flight[itinerary[i-1]].origin);
      cost -= flight[itinerary[i-1]].price;
      hour = 0;
      min = 0;
      printf("Flight has successfully been cancelled!\n");
      i--;
 }
 
  else {
   strcpy(origin, flight[itinerary[i-1]].origin);
   cost -= flight[itinerary[i-1]].price;
   hour = flight[i-1].atime_h;
   min = flight[i-1].atime_m;
   printf("Flight has successfully been cancelled!\n");
   i--;
 }
  }
  
 else if(strcmp(answer, "end") == 0) {
  break; 
 }
 
 else if(strcmp(answer, "no") == 0) {
  continue; 
 }
 i++;
}

write_itinerary(itinerary, flight, cost);


}

// Checks to see if the user wants to keep their current flight or end the itinerary after each flight choice
void getResponse(char* answer) {
printf("Would you like to cancel your last flight or end the itinerary? (cancel/end/no)");
scanf("%s", answer);
}

int checkOrigin(char* origin) {
  
if(strcmp(origin, "SBN") == 0) {
 return 1;  
}

else if(strcmp(origin, "BOS") == 0) {
  return 1;
}

else if(strcmp(origin, "ATL") == 0) {
  return 1;
}

else if(strcmp(origin, "DEN") == 0 ) {
  return 1;
}

else if(strcmp(origin, "DCA") == 0 ) {
  return 1;
}

else if(strcmp(origin, "MIA") == 0 ) {
  return 1;
}

else if(strcmp(origin, "IND") == 0) {
return 1;
}

else if(strcmp(origin, "MSP") == 0) {
  return 1;
}

else return 0;
}

// Write the external file of the itinerary.
void write_itinerary(int* itinerary, struct fl* flight, int price) {
 int i = 0;
 int x = itinerary[i];
 FILE* flightPtr;

flightPtr = fopen("itinerary.txt","w");
  fprintf(flightPtr, "EKECHUKWU TRAVEL AGENCY: Your Itinerary!\n\n");
  fprintf(flightPtr, "Origin	Destination	Departure	Arrival 	Price\n");
  while(x != 0) {
  x = itinerary[i];
  fprintf(flightPtr, "%s	%s		%d:%02d		%d:%02d		$%d\n", flight[x].origin, flight[x].dest, flight[x].dtime_h, flight[x].dtime_m, flight[x].atime_h, flight[x].atime_m, flight[x].price);
  i++;
  }

fclose(flightPtr);
 
}


