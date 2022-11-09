#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gt.h"
#include "usage.h"

int
main(int argc, char **argv)
{
	if (argc < 2) {
		usage();
	}

	if (strcmp(argv[1], "ls") == 0) {
		puts("ls");
		return cmd_ls(--argc, ++argv);
	}


	if (strcmp(argv[1], "rm") == 0) {
		puts("rm");
		return cmd_rm(--argc, ++argv);
	}

	return EXIT_SUCCESS;
}

