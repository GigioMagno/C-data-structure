#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
void main() {
	int pid, status;
	pid = fork();
	if (pid == -1) { // Error, the fork call didn't worked
		printf("Error : the fork call didn't worked\n");
		exit(1);
	} else if (pid == 0) { // Child process
		printf("hello from the child process which will execute the");
		printf(" 'ls -al' line command!\n");
		execlp("/bin/ls", "ls", "-al", NULL);
	} else { // Parent process
		printf("hello from the parent process;");
		printf(" my child pid is: %i\n", pid);
		wait(&status);
		printf("hello from the parent process;");
		printf(" my child terminated with status = %i\n", status);
	}
}
