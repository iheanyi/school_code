 /* Mortgage.c

This program will calculate the length of time  required to pay off a mortgage and the amount paid
over the period of time. 

Coded by Iheanyi Ekechukwu*/

#include <stdio.h>
#include <math.h>

int
main (void)
{

/* Declare variables */
  int years;			/* Number of years */
  int months;			/* Number of months */
  int moncount;			/* Count the months */
  float balance;		/* Remaining balance */
  float mpayment;		/* Monthly Payment */
  float principal;		/* Principal Payment */
  float rate;			/* Annual Interest Rate */
  float minterest;		/* Beginning Monthly  Interest */
  float cinterest;		/* Current interest */
  float total;			/* Total amount paid */

/* User input variables */
  printf ("Input principal amount of money borrowed: ");
  scanf ("%f", &principal);

  printf ("Input interest rate (as a decimal): ");
  scanf ("%f", &rate);

  printf ("Input desired monthly payment: ");
  scanf ("%f", &mpayment);

/* Make sure user inputs legit variables */

  if (principal <= 0)
    {
      printf ("Please re-enter a value for the principal: ");
      scanf ("%f", &principal);
    }
  if (rate <= 0)
    {
      printf ("Please re-enter a value for the interest rate: ");
      scanf ("%f", &rate);
    }

  if (mpayment <= 0)
    {
      printf ("Please re-enter a value for the monthly payment: ");
      scanf ("%f", &mpayment);
    }

/* Declare constants/beginning variables */
  minterest = (rate) / (12);
  months = 1;
  moncount = 0;
  years = 0;
  total = 0;

/* First row of table: titles */
  printf ("Month\t\tPayment\t\tInterest\tBalance\n");

/* Calculate payments over a length of time and builds table */

  while (balance > 0)
    {
      cinterest = principal * minterest;
      balance = principal - (mpayment - cinterest);
      principal = balance;

      /* Terminate program if balance increases */
      if (balance > principal)
	{
	  printf ("Desired payment too low, terminating program.");
	  return 0;
	}

       if (principal < 0)
	{
	  mpayment = mpayment + principal;
	  balance = 0;
	}

      if (moncount == 12)
	{
	  moncount = 0;
	  years = years + 1;
	}
      total = total + mpayment;
      printf ("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f", months, mpayment, cinterest,
	      balance);
      printf ("\n");
      months = months + 1;
      moncount = moncount + 1;
    }
  printf ("You paid a total of $%.2f over %d years and %d months.\n", total,
	  years, moncount);
  return 0;
}
