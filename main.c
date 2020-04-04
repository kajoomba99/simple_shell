#include "shell.h"

/**
 * main - entry point
 * Return: 0 on succes
 */

int main(void)
{
	struct stat statbuf;
	ssize_t rgetl;
	char *lineptr;
	size_t n = 0;
	pid_t rfork;
	char *ctok;
	int wstatus, rstat;
	char *argv[2];

	argv[1] = NULL;

	do {
		signal(SIGINT, &handle_signal);
		printf("#cisfun$ ");
		rgetl = getline(&lineptr, &n, stdin);
		ctok = strtok(lineptr, "\n");
		argv[0] = lineptr;
		rfork = fork();
		if (rfork == 0)
		{
			rstat = stat(argv[0], &statbuf);

			if (rstat == 0)
				execve(argv[0], argv, NULL);
			else
				perror("Error");
			return (0);
		}
		else
		{
			wait(&wstatus);
		}

	} while (rgetl != -1);
}
