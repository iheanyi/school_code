/* Graph.c

This program will graph a mathematical function in ASCII Art and also state the maximum and minimum 
values of the function.

Coded by Iheanyi Ekechukwu */

#include <stdio.h>
#include <math.h>

int
main (void)
{
/* Declare variables */

  double x;			/* X Value */
  double y;			/* Y Value */
  double min;			/* Maximum value */
  double max;			/* Minimum value */
  double xmax;			/* Where the max occurs */
  double xmin;			/* Where the min occurs */

/* Define variables */
  x = 0;
  max = 0;
  min = 1000;
/* State what the function and range is */
  printf ("A plot of y = 3*(1+cos(x)) from x = 0 to 10.0\n");

/* First row of table (headers) */
  printf ("X\tY\n");

/* Function defined and graphing */
  while (x <= 10)
    {
      y = 3 * (1 + cos (x));
      printf ("%.2f\t%.2f", x, y);

      if (y > max)
	{
	  max = y;
	  xmax = x;
	}

      if (y < min)
	{
	  min = y;
	  xmin = x;
	}

      while (y > 0)
	{
	  printf (" #");
	  y--;
	}

      x = x + 0.2;
      printf ("\n");
    }

  printf ("The max is %.2f and occurs at %.2f\n", max, xmax);
  printf ("The min is %.2f and occurs at %.2f\n", min, xmin);
  return 0;

}
