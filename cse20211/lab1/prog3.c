/* This program will calculate the Basal Metabolic Rate of
a MAN based on their weight, height, and age.

Coded by Iheanyi Ekechukwu */

#include <stdio.h>

int main (void)
{

/* Declare variables */

  int weight;			/* Weight */
  int height;			/* Height */
  int age;			/* Age */
  float BMR;			/* Basal Metabolic Rate */

/* User should input variables */

  printf ("Enter your weight in pounds: ");
  scanf ("%d", &weight);

  printf ("Enter your height in inches: ");
  scanf ("%d", &height);

  printf ("Enter your age in years: ");
  scanf ("%d", &age);

/* Calculate BMR if inputs are valid, if not, terminate 
program. */

  if (weight < 1)
    {
      printf ("Invalid input, try again with a valid input!");
      return 0;
    }

  else if (height < 1)
  {
    printf ("Invalid input, try again with a valid input!");
    return 0;

  }

  else if (age < 1)
  {
    printf ("Invalid input, try again with a valid input!");
    return 0;

  }

  else
  {
    BMR = 66 + (6.23*weight) + (12.7*height) - (6.8*age);

    printf ("Your BMR is %f\n", BMR);

  }

  return 0;

}
