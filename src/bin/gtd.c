#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

#ifndef GT_WORKER
#define GT_WORKERS 4
#endif

int gt_worker(void);

int
main(void)
{
	pid_t pid[GT_WORKERS];

	for (int i = 0; i < GT_WORKERS; i++) {
		if((pid[i] = fork()) == -1) {
			perror("fork()");
		}

		if (pid[i] == 0) {
			exit(gt_worker());
		} else {
			printf("started worker %d with pid: %d\n", i, pid[i]);
		}
	}
	
	for (int i = 0; i < GT_WORKERS; i++) {
		int status;
		pid_t child = wait(&status);
		
		if (WIFEXITED(status)) {
			int exit_status = WEXITSTATUS(status);
			printf("worker %d exited with %d\n", child, exit_status); 
		}
	}

	return EXIT_SUCCESS;
}

int
gt_worker(void)
{
	puts("worker working");
	sleep(10);
	return EXIT_SUCCESS;
}
