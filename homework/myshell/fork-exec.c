#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_TOKENS 10
#define MAX_COMMAND_CHAR 256
#define MAX_DIRECTORY_CHAR 1024
/**
* This is meant to help tokenize the command the user inputs.
* This allows for two word commands such as "cd .."
*/
int command_token (char *command, char *arguments[]) {
	int index = 0;
	/*list of characters to look out for and tokenize with*/
	char *delimiter = " \n";
	char *seperatedArguments = strtok(command, delimiter);
	/*while loop will tokenize command and store it int array arguments*/
	while(seperatedArguments != NULL){
		arguments[index] = seperatedArguments;
		seperatedArguments = strtok(NULL, delimiter);
		index++;
	}
	arguments[index] = NULL;
	return 0;

}
/**
 * This program demonstrates the use of the fork() and exec()
 * functions.
 */
int main() {
	char *arguments[MAX_TOKENS];
	char command[MAX_COMMAND_CHAR];
	char cwd[MAX_DIRECTORY_CHAR];
	printf("Welcome to the custom shell. Have fun with it\n");
	while(!feof(stdin)){
		int waitBoolean = 0;
		/*these two lines will output the directory of the shell*/
       		getcwd(cwd, sizeof(cwd));
    		printf("%s$ ",cwd);
		/*these next few commands get the input command and cleans it up a bit*/
		fgets(command, sizeof(command), stdin);
		command[strlen(command) - 1] = '\0';

		/*This command searches for an & which is sign of being run in the background
		  Also cleans up any excess spaces between '&' the commands*/
		if (command[strlen(command) - 1] == '&') {
			command[strlen(command) - 1] = '\0';
			waitBoolean = 1;
		}
		while (command[strlen(command) - 1] == ' ') {
				command[strlen(command) - 1] = '\0';
		}		
		command_token(command, arguments);
		/*Compares command to ensure it isn't a special case*/
		if (strcmp("cd", arguments[0]) == 0) {
			chdir(arguments[1]);
		} else if (strcmp("secret-system-call", arguments[0]) == 0) {
			long int result = syscall(351);
		} else if (strcmp("exit", arguments[0]) == 0) {
			return 1;
		} else{
 	   		/* Variable that will store the fork result. */
    			pid_t pid;

    	   		/* Perform the actual fork. */
    			pid = fork();
    			if (pid < 0) {
        	   	   /* Error condition. */
        	   	   fprintf(stderr, "Fork failed\n");
        	   	   return -1;
    			} else if (pid == 0) {
        	   	   /* Child process. */
        	   	   execvp(arguments[0],arguments);
    			} else {
        	  	   /* Parent process. */
        	  	   int result;
        	  	   if (!waitBoolean) {
				wait(&result);	
			   }
		        }
		}
	}
    printf("\n");
    return 0;
}
