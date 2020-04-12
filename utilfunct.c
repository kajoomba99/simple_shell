#include "shell.h"

char **sep_by_space(char *str)
{
	int len = 0;
	char **av;
	char *dupstr = _strdup(str);
	char *token = strtok(dupstr, " ");

	while (token != NULL)
		token = strtok(NULL, " "), len++;

	av = malloc(sizeof(char *) * len);

	put_args(av, str);


	return (av);
}

int count_args(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
		i++;

	return (i);
}

char **put_args(char **av, char *str)
{
	int i = 0;
	char *dupstr = _strdup(str);
	char *token = strtok(dupstr, " ");

	while (token != NULL)
	{
		av[i] = malloc(sizeof(char) * _strlen(token));
		av[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	av[i] = NULL;


	return (av);
}

char **get_params(char **args)
{
	int i = 1;
	int wc = 0;
	char **params;

	while (args[i] != NULL)
	{
		if (*args[i] != '-')
			wc++;
		i++;
	}

	params = malloc(sizeof(char) * (wc + 1));

	i = 1;
	wc = 0;
	while (args[i] != NULL)
	{
		if (*args[i] != '-')
		{
			params[wc] = malloc(sizeof(char) * _strlen(args[i]));
			params[wc] = args[i];
			wc++;
		}
		i++;
	}

	params[wc] = NULL;

	return (params);
}

void add_dir_to_struct(struct directories **head, char *directories)
{
	char *token = strtok(directories, ":");

	while (token != NULL)
	{
		add_node_end(head, token);
		token = strtok(NULL, ":");
	}
}
