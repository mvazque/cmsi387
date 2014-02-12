#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int result = syscall(83, argv[1], argv[2]);
	
	if (result == -1) {
		char *errorMessage = "There has been an error.\n Please check the strings so that the first input is a file.";
		syscall(4, 2, errorMessage, strlen(errorMessage));
	}
}
