/* Table.C
This program is simply a basic multiplication table designated to what the
end user wants.

Coded by Iheanyi Ekechukwu */

#include <stdio.h>

int
main (void)
{

/* Declare variables */

  int rnum;			/*Row number */
  int cnum;			/*Column number */
  int rows;			/*Number of rows */
  int cols;			/*Number of columns */
  int product;			/* Product of Row Number and Column Number */

/* User input number of rows and columns */

  printf ("Please enter the number of rows desired: ");
  scanf ("%d", &rows);

  printf ("Please enter the number of columns desired: ");
  scanf ("%d", &cols);

/* Build multiplication table */

  for (rnum = 0; rnum <= rows; rnum++)
    {

      for (cnum = 0; cnum <= cols; cnum++)
	{

	  if (rnum == 0 && cnum == 0)
	    {

	      printf ("*");

	    }

	 else if (rnum == 0 || cnum == 0)
	  {

		if ( cnum == 0) {
		 printf("%d", rnum);
		}
		
		else {
		printf("%4d", cnum);

		}

		}

	  else
	    {
	      product = rnum*cnum;
	      printf ("%4d", product);
	    }

	  
	}
	 printf("\n");
    }
  return 0;
}

