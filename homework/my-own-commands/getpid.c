#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char*argv[]) {
	int pid = syscall(20);
	char *message = "The PID for this process is ..." + pid;
	syscall(4, 2, message, strlen(message));
}
