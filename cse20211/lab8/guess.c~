/* Guess.c

Objective of this program is make a random word guessing game 

Coded by Iheanyi Ekechukwu */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

// Max string length
#define MAX 256

//Function prototypes
void choose_word (char* secret);
void current_word (char* word);
void guess_letter (char* guess);
void check_guess (char* current, char* guess);
int game_status (char* word, int turn);
void str_to_upper (char* word);
void play_again (char* answer);
void reset_current (char* word);
int isletter (char* guess);

char unknown[MAX];		// Global unknown word

//Main function
int main (void) {

// Declare variables
  char current[MAX];		// Currently displayed word
  int turn_no;
  char guess[MAX];		// String for guess
  int status;
  char answer[MAX];		// Answer to play again
  srand (time (NULL));		// Seed for random word

  while (1) {
      // If user does not want to play again, break the outer loop
      if (strcmp (answer, "no") == 0) {
	  break;
	}

      // Choose word, reset length of current word, set status and turn number to 0
      else {
	  choose_word (unknown);
	  reset_current (current);
	  current_word (current);
	  status = 0;
	  turn_no = 0;
	}

// Main gameplay loop
      while (1) {
	  printf ("%s\n", current);

	  guess_letter (guess);

	  check_guess (current, guess);

	  turn_no++;

	  status = game_status (current, turn_no);

// If status is 1, prompt to play again and then break the loop
	  if (status == 1) {
	      play_again (answer);
	      break;
	    }
	  printf ("%d guesses left\n", 10 - turn_no);
	}
    }

  return 0;
}

// Custom functions below

// Choose random word
void choose_word (char* secret) {
  int rand_num;

  rand_num = rand () % 17;

  switch (rand_num) {
    case 0:
      strcpy (secret, "FOOTBALL");
      break;
    case 1:
      strcpy (secret, "APPLE");
      break;
    case 2:
      strcpy (secret, "BANANA");
      break;
    case 3:
      strcpy (secret, "BASKETBALL");
      break;
    case 4:
      strcpy (secret, "BASEBALL");
      break;
    case 5:
      strcpy (secret, "IRISH");
      break;
    case 6:
      strcpy (secret, "BEACH");
      break;
    case 7:
      strcpy (secret, "CAROLINA");
      break;
    case 8:
      strcpy (secret, "STANFORD");
      break;
    case 9:
      strcpy (secret, "SWAGGER");
      break;
    case 10:
      strcpy (secret, "TABLE");
      break;
    case 11:
      strcpy (secret, "BENCH");
      break;
    case 12:
      strcpy (secret, "CAFETERIA");
      break;
    case 13:
      strcpy (secret, "ENCYCLOPEDIA");
      break;
    case 14:
      strcpy (secret, "ENGINEER");
      break;
    case 15:
      strcpy (secret, "LIBRARY");
      break;
    case 16:
      strcpy (secret, "PROGRAMMING");
      break;
    }
}

// Setup the array of stars for the currently displayed word
void current_word (char* word) {
  int length = strlen (unknown);
  int i;
  char star[MAX];

  strcpy (star, "*********************");

  strncpy (word, star, length);

//Get rid of newline
  for (i = 0; i < MAX; i++) {
      if (word[i] == '\n') {
	  word[i] = '\0';
	  break;
	}
    }
}

// Guesses a letter or string
void guess_letter (char* guess) {
int valid = 0;;
  while (valid != 1) {
      printf ("Please guess a letter or the word:");
      scanf ("%s", guess);

      valid = isletter(guess);
    }

  str_to_upper (guess);
}

void check_guess (char* current, char* guess) {
  int i;
  int no_letters = 0;		// Nui1mber of letters

// if single letter, check only one letter
  if (strlen (guess) == 1) {
      for (i = 0; i < MAX; i++) {
	  if (unknown[i] == guess[0]) {
	      current[i] = guess[0];
	      no_letters += 1;
	    }
	}

      if (no_letters == 0) {
	  printf ("There are no %cs in the word!\n", guess[0]);
	}

      else if (no_letters > 0) {
	  printf ("There are %d %cs in the word!\n", no_letters, guess[0]);
	}
    }

// If length of string greater than one letter, check whole string
  else if (strlen (guess) > 1) {
      if (strcmp (guess, unknown) == 0) {
	  strcpy (current, guess);
	}

      else {
	  printf ("Sorry, the secret word is not %s\n", guess);
	}
    }
}

// Checks whether or not the game is over yet
int game_status (char* word, int turn) {
  int is_over = 0;

  // Depends on whether the current word matches or not
  if (strcmp (word, unknown) == 0) {
      is_over = 1;
      printf ("Correct! The secret word is %s!\n", unknown);
    }

  else if (turn == 10) {
      is_over = 1;
      printf ("You ran out of guesses! Sorry!\n");
    }

  return is_over;
}

// Converts guess string to all uppercase letters
void str_to_upper (char* word) {
  int i;

  for (i = 0; i < MAX; i++) {
      word[i] = toupper (word[i]);
    }

}

// Asks user to play again
void play_again (char* answer) {
  printf ("Would you like to play again? (yes/no)\n");
  scanf ("%s", answer);

}

// Resets current board, makes it the same length as the random word
void reset_current (char* word) {
  strcpy (word, unknown);
}

// Checks if a letter is inside of the guess
int isletter (char* guess) {
  int isletter = 0;
  int length = strlen (guess);
  int i;

  for (i = 0; i < length; i++) {
      if (isalpha (guess[i])) {
	  isletter = 1;
	}

      else {
	  isletter = 0;
	  break;
	}
    }

  return isletter;

}
