#include "../apue.h"
#include <sys/wait.h>

int
main(void)
{
	char	buf[MAXLINE];
	pid_t	pid;
	int		status;

	printf("%%>");
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf)-1] = '\n')
			buf[strlen(buf)-1] = '\0';

		if ((pid = fork()) < 0) {
			fprintf(stderr, "fork error");
			exit(-1);
		} else if (pid == 0) {
			execlp(buf, buf, NULL);
			fprintf(stderr, "couldn't execute: %s", buf);
			exit(127);
		}

		if ((pid = waitpid(pid, &status, 0)) < 0)
			fprintf(stderr, "waitpid error");
		printf("%%>");
	}
	exit(0);
}
