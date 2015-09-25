/* Assigment 2

Coded by Iheanyi Ekechukwu 

Fork and Exec

February 15, 2013 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

	pid_t p_id = fork(); // Variable to store the child's process ID
    	int retval;     /* child process: user-provided return code */
    	int status;     /* parent process: child's exit status */
	
	// Check for correct usage
	if (argc != 2) {
   		printf("assignment2: assignment2 <input_file>");
   		exit(1);
   	}

   	else {
   		char* source = argv[1];

   		//execl("/usr/bin/md5sum", "md5sum", source, NULL);
		if (p_id >= 0) /* fork succeeded */
	   	{
	   		if(p_id == 0) {
	   			printf("Child Process with PID: %d\n", getpid());
	   			execl("/bin/cp", "cp", source, "CloneFile", NULL);
	   		}

	   		else {
	   			printf("Parent Process with PID: %d\n", getpid());
	   			wait(&status);
	   			execl("/usr/bin/md5sum", "md5sum", "CloneFile", NULL);
	   			exit(0);
	   		}


	   	}
		else {
			// Code only executed by parent process
			perror("fork");
			exit(0);
		}
	}

	return 0;
}
