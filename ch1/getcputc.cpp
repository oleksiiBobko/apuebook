#include "../apue.h"

int main(void)
{
	int c;
	while ((c = getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF) {
			fprintf(stderr, "output error");
			exit(-1);
		}
	if (ferror(stdin)) {
		fprintf(stderr, "input error");
		exit(-1);
	}
	exit(0);
}
