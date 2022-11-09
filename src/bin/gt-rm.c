#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usage.h"

int
cmd_rm(int argc, char **argv)
{
	int a_flag = 0;
	int b_flag = 0;
	
	int ch;
	while((ch = getopt(argc, argv, "ab")) != -1) {
		switch (ch) {
		case 'a':
			a_flag = 1;
			break;
		case 'b':
			b_flag = 1;
			break;
		default:
			usage();
		}
	}

	if (a_flag != 0) puts("has a defined");
	if (b_flag != 0) puts("has b defined");

	return EXIT_SUCCESS;
}
