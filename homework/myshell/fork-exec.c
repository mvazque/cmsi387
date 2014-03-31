#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_TOKENS 10

int command_token (char *command, char *arguments[]) {
	int index = 0;
	char *delimiter = " \n";
	char *seperatedArguments = strtok(command, delimiter);

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
int main(void) {

	char *arguments[MAX_TOKENS];
	char command[256];
	char cwd[1024];
	printf("Welcome to the custom shell. Have fun with it\n");
	while(!feof(stdin)){
    	   /* String to hold the command to run. */
		int waitBoolean = 0;
       		getcwd(cwd, sizeof(cwd));
    		printf("%s$ ",cwd);
		fgets(command, sizeof(command), stdin);
		command[strlen(command) - 1] = '\0';
		
		while (command[strlen(command) - 1] == ' ') {
			command[strlen(command) - 1] = '\0';
		}
		if (command[strlen(command) - 1] == '&') {
			command[strlen(command) - 1] = '\0';
			waitBoolean = 1;

			/* Remove any extra spaces, just in case. */
			while (command[strlen(command) - 1] == ' ') {
				command[strlen(command) - 1] = '\0';
			}
		}
		command_token(command, arguments);

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
    return 0;
}
