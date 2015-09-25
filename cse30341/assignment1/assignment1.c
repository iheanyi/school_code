/* Assignment I

Coded by Iheanyi Ekechukwu

Basic signal handling

January 17, 2013
*/
#include <stdio.h>
#include <signal.h>

//using namespace std;

char bKeepLooping = 1;

void signalHandler(int signalValue); //Prototype for the function

int main(int argc, char *argv[]) {


	signal(SIGINT, signalHandler); // Get ready to receive the signal

	// Just perform an infinite loop
	while(bKeepLooping) {
	}

	printf("Exited successfully\n"); // Print message successfully
	return 0;

}

void signalHandler( int signalValue) {

	printf("Interrupt signal received.\n");
	bKeepLooping = 0; // Set looping to false, in order to break loop
	
}