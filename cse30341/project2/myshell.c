/* Iheanyi Ekechukwu

Project 2: Working with Forks and Threading . . . This was so terrible */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

/* Function Prototypes */

void unknownCommand(char*);

int main(int argc, char* argv[]) {


    // Declare line (with buffer and the words array)
	char line[4096];
    char* words[100];



    // Start shell execution loop
    while(1) {
        // Define loop variables
        int counter = 0;

        // Shell input
    	printf("myshell> ");
        fflush(stdout);
    	char* input = fgets(line, 4096, stdin);

        if(input == NULL) {
            break;
        }
    
        // Define tokenizer
    	char* tok = strtok(line, " \t\n");

        // No input? Reconfirm. 
        if(tok == NULL) {
            printf("\n");
            continue;
        }

        else {

            // Loop over the token strings
            while(tok != NULL) {
                words[counter] = tok;
                tok = strtok(NULL, " \t\n");
                ++counter;
            }
        }

        // Set string to shit
        words[counter] = 0;

        // Conditionals for each separate command


        // Define process ids outside of loop
        pid_t p_id;
        int status;     
        if(strcmp(words[0], "start") == 0) {
            p_id = fork(); // On start, fork a new process

            if(p_id >= 0) {
                if(p_id == 0) {
                    printf("myshell: process %d started\n", getpid());
                    execvp(words[1], words + 1); // Increment words by 1, to skip over first command

                }
                else {
                }
            }

            else {
                perror("forking failed"); // Throw error
                exit(1);
            }
        }
        
        else if(strcmp(words[0], "wait") == 0) {
            pid_t result = wait(&status);

            if(result == -1) {
                printf("myshell: %s\n", strerror(errno));
            }

            else {
                if(status == 0) {
                    printf("myshell: process %d exited normally with status %d\n", result, WEXITSTATUS(status));
                }
                else {
                    printf("myshell: process %d exited abnormally with signal %d: %s\n", result, status, strsignal(status) );
                }            
            }
        }
        else if(strcmp(words[0], "run") == 0) {
            // Forking
            p_id = fork();


            // If valid fork, start process and wait for it to terminate
            if(p_id >= 0) {
                if(p_id == 0) {
                    printf("myshell: process %d started\n", getpid());
                    execvp(words[1], words+1);                    
                }

                else {
                    pid_t exited = waitpid(p_id, &status, 0);

                    if(exited == -1) {
                        printf("myshell: wait error: %s", strerror(errno));
                    }

                    if(status == 0) {
                        printf("myshell: process %d exited normally with status %d\n", exited, WEXITSTATUS(status));
                    } else {
                    printf("myshell: process %d exited abnormally with signal %d: %s\n",exited, status, strsignal(status) );
                    }
                }

            }

            // Else throw an error
            else {
                perror("forking failed");
                exit(1);
            }

        }
        else if(strcmp(words[0], "kill") == 0) {


            // Kill the process, store result 
            pid_t killprocess = atoi(words[1]);
            int result = kill(killprocess, SIGKILL);

            // If there is a -1 result, there was an error
            if(result == -1) {
                printf("myshell: process error: %s\n", strerror(errno));
            }


            // Else, it was successfully killed
            else {
                printf("myshell: process %s killed\n", words[1]);
            }
        }

        else if(strcmp(words[0],"continue") == 0) {
                        // Check status of process, make sure it exists


            // Continue the process
            pid_t killprocess = atoi(words[1]);
            int result = kill(killprocess, SIGCONT);
            
            if(result == -1) {
                printf("myshell: process error: %s\n", strerror(errno));
            }

            else {
                printf("myshell: process %s continued.\n", words[1]);
            }
        }
        else if(strcmp(words[0], "stop") == 0 ) {
            // Stop the process
            pid_t killprocess = atoi(words[1]);
            int result = kill(killprocess, SIGSTOP);
            
            if(result == -1) {
                printf("myshell: process error: %s\n", strerror(errno));
            }

            else {
                printf("myshell: process %s stopped.\n", words[1]);
            }

        }
        else if(strcmp(words[0], "exit") == 0) {
            exit(0);
        }
        else if (strcmp(words[0], "quit") == 0) {
            exit(0);
        }
        else {
            printf("myshell: unknown command: %s\n", words[0]);
        }  
    }

    return 0;
}