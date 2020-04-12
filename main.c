#include "shell.h"

int main()
{
	ssize_t nread = 0;
	size_t len = 0;
	char *line = NULL;
	pid_t rfork;
	int status = 0;

	if (!isatty(0))
	{
		nread = getline(&line, &len, stdin);
		strtok(line, "\n\t\r");
		start_func(line);
	}
	else
	{
		do
		{
			write(STDOUT_FILENO, "$ ", 2);
			nread = getline(&line, &len, stdin);

			if (nread == EOF)
			{
				write(STDOUT_FILENO, "\n", 1);
				free(line);
				exit(0);
			}

			if(_strcmp(line, "exit\n") == 0)
				exit(0);

			if (_strcmp(line, "env\n") == 0)
				env();

			rfork = fork();
			if (rfork == 0)
			{
				strtok(line, "\n\t\r");
				start_func(line);
			}
			else
			{
				wait(&status);
			}

		} while (nread != -1);
	}
	return (0);
}
