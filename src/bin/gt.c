#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int cmd_ls(int, char **);
static int cmd_rm(int, char **);

static void usage(void);

int
main(int argc, char **argv)
{
	if (argc < 2) {
		usage();
	}

	if (strcmp(argv[1], "ls") == 0) {
		puts("list");
		return cmd_ls(--argc, ++argv);
	}


	if (strcmp(argv[1], "rm") == 0) {
		puts("delete");
		return cmd_rm(--argc, ++argv);
	}

	return EXIT_SUCCESS;
}

static void
usage(void)
{
	(void)fprintf(stderr, "usage");
	exit(EXIT_FAILURE);
}

static int
cmd_ls(int argc, char **argv)
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
	if (b_flag != 0) puts("has a defined");

	return EXIT_SUCCESS;
}

static int
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
	if (b_flag != 0) puts("has a defined");

	return EXIT_SUCCESS;
}
