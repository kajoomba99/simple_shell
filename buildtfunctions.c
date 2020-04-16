#include "shell.h"
/**
 * _strcat - function that concat two string
 * @fstr: first string
 * @sstr: second string
 * Return: char that contains the two string concatenated.
 */
char *_strcat(char *fstr, char *sstr)
{
	char *concat = NULL;
	int lens1 = 0, lens2 = 0, i = 0, j = 0;

	lens1 = _strlen(fstr);

	lens2 = _strlen(sstr);

	concat = malloc((lens1 + lens2 + 1));

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

/**
 * _strlen - function that count how many elements are in a string
 * @str: String the it will count the elements
 * Return: the number of characters of a string
 */
int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (str[i] != '\0')
		i++;

	return (i);
}

/**
 * _which - function to get the Path of a binary file
 * @head: pointer to the first element of a linked list that contains the
 * the directions where can be allocated the binary file
 * @dir: name of a binary file that we will search
 * Return: the path where the binary file is located
 */
char *_which(directs **head, char *dir)
{
	struct stat st;
	directs *dup = *head;
	char *ruta = NULL;
	char *rutaComp = NULL;

	if (stat(dir, &st) == 0)
	{
		return (dir);
	}
	else
	{
		while (dup != NULL)
		{
			ruta = _strcat(dup->direct, "/");
			rutaComp = _strcat(ruta, dir);
			if (stat(rutaComp, &st) == 0)
			{
				free(ruta);
				return (rutaComp);
			}
			dup = dup->next;
			free(ruta);
			free(rutaComp);
		}
	}
	return (dir);
}

/**
 * _getenv - function to get the value of an environment variable
 * @name: name of the environment variable
 * Return: the value of the environment variable
 */
char *_getenv(const char *name)
{
	char *dup = _strdup(name);
	char *value = NULL;
	char *token = NULL;
	int i = 0;
	
	for (i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");
		if (strcmp(dup, environ[i]) == 0)
		{
			token = strtok(NULL, "=");
			value = token;
			break;
		}
	}

	free(dup);
	return (value);
}

/**
 * _strdup - function to duplicate a string
 * @str: string to be duplicated
 * Return: duplicate of the string
 */
char *_strdup(const char *str)
{
	int i = 0, j = 0;
	char *p;

	if (str == NULL)
		return (NULL);

	while (str[i])
		i++;

	p = malloc(sizeof(char) * (i + 1));

	if (p == NULL)
		return (NULL);

	while (j < i)
	{
		p[j] = str[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}
