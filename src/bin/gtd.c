#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void usage(void);

int
main(int argc, char **argv)
{
	int f_flag = 0;
	
	int ch;
	while((ch = getopt(argc, argv, "ft:u:")) != -1) {
		switch (ch) {
		case 'f': /* start in foreground */
			a_flag = 1;
			break;
		default:
			usage();
		}
	}

	if (f_flag != 0) puts("has f defined");

	return 0;
}

static void
usage(void)
{
	(void)fprintf(stderr, "usage");
	exit(EXIT_FAILURE);
}

