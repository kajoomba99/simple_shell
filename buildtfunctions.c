#include "shell.h"

char *_strcat(char *fstr, char *sstr)
{
	char *concat;
	int lens1 = 0, lens2 = 0, i = 0, j = 0;

	while (fstr[i] != '\0')
		lens1++, i++;

	i = 0;
	while (sstr[i] != '\0')
		lens2++, i++;

	concat = malloc(sizeof(char) * (lens1 + lens2));

	for (i = 0; i < lens1; i++)
	{
		concat[i] = fstr[i];
	}

	for (j = 0; i < (lens1 + lens2); i++, j++)
	{
		concat[i] = sstr[j];
	}
	concat[i] = '\0';

	return (concat);
}

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}

char *_which(directs **head, char *dir)
{
	struct stat st;
	directs *dup = *head;
	char *ruta;
	if (stat(dir, &st) == 0)
	{
		return (dir);
	}
	else
	{
		while (dup != NULL)
		{
			ruta = strcat(dup->direct, "/");
			ruta = strcat(dup->direct, dir);
			if (stat(ruta, &st) == 0)
			{
				return (ruta);
			}
			dup = dup->next;
		}
	}

	return (NULL);
}

char *_getenv(const char *name)
{
	extern char **environ;
	char *dup = strdup(name);
	char *dupenv;
	char *value;
	char *token;

	for (size_t i = 0; environ[i] != NULL; i++)
	{
		dupenv = strdup(environ[i]);
		token = strtok(dupenv, "=");
		if (strcmp(dup, dupenv) == 0)
		{
			token = strtok(NULL, "=");
			value = token;
			break;
		}
	}

	return (value);
}
