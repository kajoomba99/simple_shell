#include "shell.h"

/**
 * main - entry point
 * Return: 0 on success
 */

int main(void)
{
	ssize_t nread = 0;
	char *line = NULL;
	size_t len = 0;

	if (!isatty(0))
	{
		nread = getline(&line, &len, stdin);
		strtok(line, "\n\t\r");
		start_func(line);
	}
	else
	{
		signal(SIGINT, &handle_signal);
		do {
			exect_prompt();
		} while (nread != -1);
	}
	return (0);
}

/**
 * exect_prompt - function to execute the prompt to receive data from stdin
 */
void exect_prompt(void)
{
	pid_t rfork;
	int status = 0;
	size_t nread = 0;
	char *line;
	size_t len = 0;

	line = malloc(sizeof(char) * 1024);
	write(STDOUT_FILENO, "$ ", 2);
	nread = getline(&line, &len, stdin);
	/*End of file, condition*/
	if (nread == EOF)
	{
		write(1, "\n", 1);
		free(line);
		exit(0);
	}
	if (_strcmp(line, "exit\n") == 0)
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
	free(line);
}
