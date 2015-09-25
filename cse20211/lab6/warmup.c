/* Warm up.c

Computes and displays the average and standard deviation of the array.

Uses a bubble sort algorithm to sort the values.

Displays the sorted values on the output.

Coded by Iheanyi Ekechukwu */

#include <stdio.h>
#include <math.h>
#define SIZE 10 

// Function prototypes
void gen_array(double b[], int size);	// Generates array
double sum_array(double b[], int size); // Sum of the array
double avg_array(double b[], int size); // Average
double dev_array(double b[], int size); // Standard Deviation
void sort_array(double b[], int size); // Sort array
void display_result(double b[], int size); // Displays all results

//  Main function
int main( void ) {

  // Declare variables
  double a[ SIZE ] = {0};
  double avg; // Average of array
  double sum; // Sum of array
  
  // Generate array
  gen_array(a, SIZE);
  
  // Sort array
  sort_array(a, SIZE); 
  
  // Display results
  display_result(a, SIZE);
  
  return 0; 
}

void gen_array(double b[], int size) {
int i;
for(i = 0; i < SIZE; i++) {
    printf("Please enter number %d: \n", i+1);
    scanf("%lf", &b[i]);
  }

}

double sum_array(double b[], int size) {
      int i;
      double sum = 0;
      for(i = 0; i < SIZE; i++) {
		sum = sum + b[i];
      } 
      return sum; 
 }

double avg_array(double b[], int size) {
  double avg;
  double sum = sum_array(b, size);
  avg = sum/size;
  return avg;
}

double dev_array(double b[], int size) {
double avg = avg_array(b, size);
int i;
double total = 0;
double std_dev; // Standard deviation
for (i = 0; i < SIZE; i++) {
	total += (avg-b[i])*(avg-b[i]);
	
	}
	
std_dev = sqrt(total/SIZE-1); 

return std_dev;
}

void sort_array(double b[], int size) {
int i; // First counter
int j; // Second counter, nested loop
double sortnumber; // For replacing the number

for (i = 0; i < SIZE; i++) {
	for (j = 0; j < SIZE - 1; j++) {
		if(b[j] > b[j+1]) {
			sortnumber = b[j+1];
			b[j+1] = b[j];
			b[j] = sortnumber; 
		}
	}
}
}

void display_result(double b[], int size) {
  double sum = sum_array(b, size);
  double avg = avg_array(b, size);
  double std_dev = dev_array(b, size);
  int i;

  printf("Sum of the array is: %.2f\n", sum);
  printf("Average of the array is: %.2f\n", avg);
  printf("Standard deviation of the array is: %.2f\n", std_dev);
  // Print sorted array
  printf("The sorted array is: ");
  for(i = 0; i < SIZE; i++) {
  printf("%.2f ", b[i]);
  }
}
