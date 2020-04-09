#include "shell.h"

char **flags(char **args)
{

	int i = 0, fc = 0;
	char **flags;

	while (args[i] != NULL)
	{
		if (*args[i] == '-')
			fc++;
		i++;
	}

	flags = malloc(sizeof(char *) * (fc + 1));
	fc = 0;
	i = 0;
	while (args[i] != NULL)
	{
		if (*args[i] == '-')
		{
			flags[fc] = malloc(sizeof(char) * _strlen(args[i]));
			flags[fc] = args[i];
			fc++;
		}
		i++;
	}
	flags[fc] = NULL;

	return (flags);
}
