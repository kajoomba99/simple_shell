#include "shell.h"
/**
 * sep_by_space - function to split a string into spaces " "
 * @str: string to be splited
 * Return: an array of the elements that we split by spaces
 */
char **sep_by_space(char *str)
{
	int len = 0;
	char **av;
	char *dupstr = _strdup(str);
	char *token = strtok(dupstr, " ");

	while (token != NULL)
		token = strtok(NULL, " "), len++;

	av = malloc(sizeof(char *) * (len + 1));

	put_args(av, str);


	return (av);
}

/**
 * count_args - count the number of elements od an 2D array
 * @arr: 2D array
 * Return: number of elements of the 2D array
 */
int count_args(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
		i++;

	return (i);
}

/**
 * put_args - separe a string into spaces and put each element in an array
 * @av: array that will recoive the elements
 * @str: string to be separed
 * Return: @av filled with the elements
 */
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
/**
 * get_params - to get the elements of a list of arguments that start with an
 * character diferent to "-".
 * @args: array with the arguments
 * Return: 2D array with these arguments
 */
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

/**
 * add_dir_to_struct - add the directions contained on the environment variable
 * PATH.
 * @head: pointer to the first element of a linked list
 * @directories: value of the environment varable PATH
 */
void add_dir_to_struct(struct directories **head, char *directories)
{
	char *token = strtok(directories, ":");

	while (token != NULL)
	{
		add_node_end(head, token);
		token = strtok(NULL, ":");
	}
}
