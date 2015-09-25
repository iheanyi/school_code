/* Football Formula Calculator
Calculates the score from the toucdowns, field goals, and safeties of the
Irish football team.

Created by Iheanyi Ekechukwu */

#include <stdio.h>

int main( void )
{
/* Prompt user for inputs and use */

   int t; /* Touchdowns */
   int p;  /* Extra points */
   int f; /* Field goals */
   int s; /* Safeties */
   int sum; /* Total */
 
   printf("Enter the number of touchdowns scored: ");
   scanf("%d", &t);

   printf("Enter the number of extra points scored: ");
   scanf("%d", &p);

   printf("Enter the number of field goals made: ");
   scanf("%d", &f);

   printf("Enter the number of safeties occurred: ");
   scanf("%d", &s);

/* Calculate the total score */

   sum = (6*t) + p + (3*f) + (2*s);

   printf( "Total score for this game: %d\n", sum );

return 0;
}

