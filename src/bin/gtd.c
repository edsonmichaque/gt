#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

#ifndef GT_WORKERS
#define GT_WORKERS 4
#endif

int gt_worker(void);
int gt_master(int);

int
main(void)
{
	return gt_master(GT_WORKERS);
}

int
gt_master(int workers)
{
	pid_t pid[workers];

	for (int i = 0; i < workers; i++) {
		if((pid[i] = fork()) == -1) {
			perror("fork()");
			fprintf(stderr, "Failed to create worker %d\n", i);
			fprintf(stderr, "Killing all previouly created processes\n");

			for (int j = 0; j < i; j++) {
				if ((kill(pid[j], SIGKILL)) == -1) {
					perror("kill()");
				}
			}

			exit(EXIT_FAILURE);
		}

		if (pid[i] == 0) {
			exit(gt_worker());
		} else {
			printf("started worker %d with pid: %d\n", i, pid[i]);
		}
	}
	
	for (int i = 0; i < workers; i++) {
		int status;
		pid_t child_pid;
		if ((child_pid = wait(&status)) == -1) {
			perror("wait()");
		}
	
		if (WIFEXITED(status)) {
			int exit_status = WEXITSTATUS(status);
			printf("worker %d exited with %d\n", child_pid, exit_status); 
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
