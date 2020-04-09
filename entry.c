
#include "shell.h"

int start_func(char *line)
{

	char **dbl, **tags, **params, **refav;
	char *reswhich;
	directs *head = NULL;
	char *directories = _getenv("PATH");
	int cpar = 2, i = 0, j = 0;

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

	if (count_args(refav) > 1 && flags(refav))
	{
		i = 1;
		j = 0;
		while (tags[j] != NULL)
		{
			dbl[i] = malloc(_strlen(tags[j]));
			dbl[i] = tags[j];
			i++, j++;
		}

		j = 0;

		while (params[j] != NULL)
		{
			dbl[i] = malloc(_strlen(params[j]));
			dbl[i] = params[j];
			i++, j++;
		}
		dbl[i] = NULL;
	}
	else
	{
		dbl[1] = NULL;
	}
	execve(dbl[0], dbl, NULL);

	return (0);
}