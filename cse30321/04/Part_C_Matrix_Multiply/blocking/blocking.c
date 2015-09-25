#include <stdio.h>
#include <math.h>

#define XSIZE 200
#define YSIZE 200

#ifndef min
	#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif

int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k;
  
  int r;

  int jj, kk;

  int temp;
    
  int B = 80;

	/* Initialize y matrix */
	for(i=0; i<XSIZE; i++) {
		for(j=0; j<YSIZE; j++) {
			temp = rand() % 1000;
            y[i][j] = temp;
		}
	}
	
	/* Initialize z matrix */
	for(i=0; i<XSIZE; i++) {
		for(j=0; j<YSIZE; j++) {
			temp = rand() % 1000;
            z[i][j] = temp;
            
		}
	}

  /* Do matrix multiply */
  for(jj=0; jj<XSIZE; jj=jj+B)
  for(kk=0; kk<YSIZE; kk=kk+B)
  for(i=0; i<XSIZE; i=i+1)
    for(j=jj; j<min(jj+B,YSIZE); j=j+1)
     {
      r=0;
      for(k=kk; k<min(kk+B,XSIZE); k=k+1)
        r = r + y[i][k]*z[k][j];
      x[i][j] = x[i][j] + r;
     }
}
