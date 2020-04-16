#include "shell.h"
/**
 * start_func - Receive the input and start the process to execute the command.
 * @line: is the input received from the stdin.
 * Return: 0 on success.
 */
int start_func(char *line)
{
	char **dbl = NULL, **tags = NULL, **params = NULL;
	char **refav = NULL, **rtgs = NULL;
	char *reswhich = NULL;
	directs *head = NULL;
	char *directories = _getenv("PATH");
	int cpar = 2, nargs = 0;

	add_dir_to_struct(&head, directories);
	refav = sep_by_space(line);
	reswhich = _which(&head, refav[0]);

	if (count_args(refav) > 1 && flags(refav))
	{
		params = get_params(refav);
		tags = flags(refav);
		cpar += count_args(tags);
		cpar += count_args(params);
	}
	dbl = malloc(sizeof(char *) * cpar);
	dbl[0] = malloc(_strlen(reswhich));
	dbl[0] = _strdup(reswhich);
	dbl[1] = NULL;
	nargs = count_args(refav);
	rtgs = flags(refav);

	if (nargs > 1 && rtgs)
	{
		put_stuff_in_dbl(dbl, tags);
		put_stuff_in_dbl(dbl, params);
	}
	free_dbl_arr(refav);
	free_list(head);
	execve(dbl[0], dbl, environ);
	error_printer(dbl[0]);
	free_dbl_arr(dbl);
	fflush(stdin);
	_exit(127);
}

/**
 * put_stuff_in_dbl - This function is used to concat elements from a 2D array
 * to another.
 * @dbl: Array tha receivesthe elements from @stuff
 * @stuff: Array 2D
 */
void put_stuff_in_dbl(char **dbl, char **stuff)
{
	int iarg = count_args(dbl);
	int i = 0;

	while (stuff[i] != NULL)
	{
		dbl[iarg] = malloc(_strlen(stuff[i]));
		dbl[iarg] = stuff[i];
		iarg++, i++;
	}

	dbl[iarg] = NULL;
}
/**
 * free_dbl_arr - free_dbl_arr
 * @arr: arr
 */
void free_dbl_arr(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
		free(arr[i]), i += 1;
	free(arr);
}
