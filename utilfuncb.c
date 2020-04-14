#include "shell.h"
/**
 * _strcmp - function to compare if two string are equals.
 * @s1: string to be compared with s2
 * @s2: string to be compared with s1
 * Return: 0 if the strings are equal.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;

	return (s1[i] - s2[i]);
}

/**
 * env - function to print the environment valiables
 * Return: 0 on success
 */
int env(void)
{
	int len = 0;

	for (size_t i = 0; environ[i] != NULL; i++)
	{
		len = strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}
