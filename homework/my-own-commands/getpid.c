#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

int main(int argc, char*argv[]) {
    // JD: OK, this works, though in this context not *that* useful :)
	pid_t pid = syscall(20);
	printf("The PID for this process is ... %d \n", (int)pid);
}
