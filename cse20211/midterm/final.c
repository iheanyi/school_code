/* Final.c

Study guide for the final exam. */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void someFunction(const int b[], int startIndex, int size);

int main(void) {

  int a[SIZE]={8,3,1,2,6,0,9,7,4,5};/*initialize a*/
  
  printf("Answer is:\n");
  someFunction(a, 0, SIZE);
  printf("\n");
  return 0;
}

void someFunction(const int b[], int startIndex, int size) {
 if (startIndex < size) {
   someFunction(b, startIndex+1, size);
   printf("%d", b[startIndex]);
 }
}