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

    // JD: Oh snap, it's dogeshell :-P
	printf("++???++++++++++?II????++++II7?====~~~~~~~~~~~:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n++++?++?++++??+?+++++====+?I77?+==~~~~~~~~~~~:~~~~~~:~~~~~~~~~+??I7?~~~~~~~~~~~~\n??+++?????????++=++==~~=++?7777I+~~~~~~~~~::~~~~~~::~~~~~~~~~+?777$$?~~~~~~~~~~~\n?????????????++=====~~===+?77$77I?~~~~~~~~~~~~~~~~~~~~::~~~++IIII7$Z$?~~~~~~~~~~\n??????++++=+======~~~~==+??I7$$7I7I+~~~~~~~~~~~~::~::~~~~~+?I7I777$$ZZ=~~~~~~~~~\n++=======~=~~~==~~~===++?I777??????I?????+=~~~~~~~:~~~~~+II$$II777$$$ZI~~~~~:~~:\n===~~==~===++=========???I?????????????III???IIIIIIII???I77Z7777$ZZ$$$$=~~~~~~~~\n=~=~~==========+++??????++++?????IIIIIIII?I???????III$777$ZZ7$$ZZZZ$$7$+~~~~~~~~\n====++++++??I?II7I7I?++++++++????IIIIIIIII?????????III$$$OZ$7$ZO8DDZ$$$I~~~::~~:\n++??I?II7777777II?++++++=+++???IIIIIIII?IIIIIIII??IIIII$OZ$$777ZODDO$7$$~~~~~~~~\n77777$777777I?+++===++++=+++?IIII7III?II?I????I?I??I?IIII$ZZ7$$ZND8Z$777~~~~~~~~\n$777777777I?+=====++++===++?II77IIIIII????????III?I??III??$$$7OND88Z7777~~~~~~~~\n7777777II?+======++++=====??I77IIII???????II???III?II??I???I$8DDD8Z7I77I~~~::~~~\n7777IIII?+=+====++++=+====?I77II?????????????I??I?????????I??778OZ$$77ZI~~~~~~~:\n7I77III?=======++?++?+++++II7III?+++++??II?I??I?????????I?????I7$7777877=~~~~~~~\n7IIIII?+==~~~~=+$887I?+++II7I7I?+=+++++?IIII??I??II??+??I???????I7777777+=~~~:~~\nI?????+==~:::~=$??DN8I+???IIII?++++++++???I7IIIIII????+???????++??777ZZ$?+=~~~~~\n+=======~::::~==DDNND???+++?+???+++??$7I?III777III??????+??????+++?7$$Z$7?+~~~~~\n==~=~=~~::::~~?78OON???++++++????IID8OMMNO77IIIII????????????????+??I7OO7I+=~~~~\n======~::::~==+I$ZI+++++++=++II7Z8N7+DDNDMD7II???????????????I??????I77Z$I?=~~~~\n=~===~:::::~+++++=+++++==++++?7$ODDIONNMND8I????++++??+++????????????I7$7I?=~~~~\n===~=~:::::~=+===+=======++++?III8D8$NDDO$+++++=====+++++++++?++?????II7III+~~~~\n=====::::::~~~~=++=+++++=++++?I??+??II??+++++========++++++++++++++????II7I+~~~~\n====~::~~::~?777$7II?+====++++??++?I?I????+++======++++====++++=++++???IIII?~~~~\n+++==~::::=DDDNDDO88OI+====++++++++++??????+=====~~~==============+++++?III?=~~~\n++?====~::INMDNNMMNNDD?==~===++++=+=====++========~==============++++++??I??+~~~\n++=~:~~~:~I78NNNMMMNN8?=====+==+=======~===================~======+=++++????|=~~\n++=~~~~~~+IDDDNNNNDN8Z?+==+=++++====================++++===========+++++?????+~~\n++==~~~=+?7ODNMNNNDO$7?7+====+++=====+========++=+=+++++===+==++++++++??II???|=~\n?+~~~~~=+I$OO8NDD88$$I++I?+???+++=+=++========+===++++=====++++++++????III???+=~\n++~~~~~=+?$ZZZ8OO88O7I??+++?+?+?++++++++==+?++++++++++++++++++++++?+???I7II???+~\n++=~~~~==+?ONMMMMOO8Z$III??I??II7I?+++?++????++++?++++++=++??????++???II7I??I?+=\n++~~~~~~~=+Z888DDNNNNOI?I???I7$$$???++++???++++++++++++++?+++++++++???II77III??+\n===~~~~~===?7O88DDDD8DNMZDDDN8OZ7???+???++++++++++++++++++++++++++???III7IIII??+\n:::~~~~~====?I$ZZ$ZZ$OO8O$Z$$7$I??++++??++++++++++++++++++=====++++???III?III??+\n:::~~~~~~==+++I$77$7III7I777III?++???????++++++++++++++=++==+++++++?IIIIIIIIII?+\n:::~~~~=======++??+????II???++??????+?????++++=++++=+=+++++++++++??III7IIIIIIII?\n~~:~~~~===+=====+++++++????????????????++++++++++?+++++++++++++????IIII777777II?\n~~~:~=~=======++++++????+????????I????+++++++++++++++++++++++++???IIIII77777IIII\n~~~~~+========++++++++???????????????++++++++++?++++++++++++????IIIII7II7$$77III\n~~~~~=++==+==+++?++++???????????????+++++++++++++++=+==+?++?II??II77II777$7IIII?\n~~~~===+++++=++++++++????????????I????+?+++++++++++++++++?????IIIIII7777$77IIII?\n~~~~~==++++++++++++++????????????????????++++++==++++??????????II7777$$$77IIII??\n~~~~===++++??++++++++??????????????????++++++++++????+????I???I?II7777777?II???+\n~~~~=====++++???+++++?????????I??????????????+++?????????++???IIII77777I???+++++\n=~~~~====+++++????????????????????????????I????????+?+??+??I??IIII777I?I???+++++\n==~~~==~==++++++?IIIIIII?IIIIIIIIIIIIIIIIII??????+++??I?+?????IIII???++++++++++=\n===~~~~~====+++?+??IIIIIII77777IIIIII?I?I?????+??++++++?+?+?IIII?++??+++++++++?+\n===~~~~~====+=+++????IIIII?IIIIIIII????+++++++??+++??++?+?+???+++++====+++++++?=\n====~~~~~====++++??????IIIIII??????+++++++?????+?++++++++++++=+====+==++++++++?+\n\nVery shell! So doge! Much wow!\n");
	while(!feof(stdin)){ // JD: Spacing here is inconsistent with spacing in line 55. (I like line 55 better)
		int waitBoolean = 0;
		/*these two lines will output the directory of the shell*/
        // JD: They are indented to the wrong level...because of TAAAAABS!
       		getcwd(cwd, sizeof(cwd));
    		printf("%s$ ",cwd);
		/*This command will recieve the input from the user*/
		fgets(command, sizeof(command), stdin);

		/*These next two parts are meant to clean the input so that the 						      			*program doesnt accidentally try and run a blank command and seg fault
		*/
		
		command[strlen(command) - 1] = '\0';
		while (command[strlen(command) - 1] == ' ') {
			command[strlen(command) - 1] = '\0';
		}
		if(strlen(command) != 0){

			/*This command searches for an & which is sign of being run in the background
			  Also cleans up any excess spaces between '&' the commands*/
			
			if (command[strlen(command) - 1] == '&') {
				command[strlen(command) - 1] = '\0';
				waitBoolean = 1;
				while (command[strlen(command) - 1] == ' ') {
					command[strlen(command) - 1] = '\0';
				}
			}		
			command_token(command, arguments);
			/*Compares command to ensure it isn't a special case*/
			if (strcmp("cd", arguments[0]) == 0) {
				chdir(arguments[1]);
			} else if (strcmp("secret-system-call", arguments[0]) == 0) {
				long int result = syscall(351); // JD: May as well do something with result!
			} else if (strcmp("exit", arguments[0]) == 0) {
				return 1;
			} else{ // JD: These are just too tight.  Space things out better please.
				if(strcmp("./a.out",arguments[0]) == 0){
					printf("Dogeception\n"); // JD: LOL.
				}
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
					wait(&result); // JD: This line looks improperly indented in my editor.
				   } // JD: Why was that...?  Oh yes...TAAAAAAABS!!!
			        }
			}
		}
	}
    printf("\n");
    return 0;
}
