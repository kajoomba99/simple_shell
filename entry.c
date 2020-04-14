#include "shell.h"
/**
 * start_func - Receive the input and start the process to execute the command.
 * @line: is the input received from the stdin.
 * Return: 0 on success.
 */
int start_func(char *line)
{
	char **dbl = NULL, **tags = NULL, **params = NULL, **refav = NULL;
	char *reswhich = NULL;
	directs *head = NULL;
	char *directories = _getenv("PATH");
	int cpar = 2;

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
	dbl[0] = reswhich;
	dbl[1] = NULL;

	if (count_args(refav) > 1 && flags(refav))
	{
		put_stuff_in_dbl(dbl, tags);
		put_stuff_in_dbl(dbl, params);
	}

	execve(dbl[0], dbl, environ);

	return (0);
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
