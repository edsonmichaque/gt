#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

int
main(void)
{
	pid_t pid;

	if ((pid = fork()) == -1) {
		perror("fork()");
	}

	if (pid == 0) {
		int status = worker();
		
		exit(status)
	} else {
		puts("master");
	}

	wait(NULL);

}

int
worker(void)
{
	puts("worker");

	exit(EXIT_SUCCESS);
}
