#include "shell.h"

struct directories *add_node_end(struct directories **head, const char *str)
{
	int len = 0;
	struct directories *new = malloc(sizeof(struct directories));
	struct directories *last = *head;

	if (!new)
		return (NULL);

	new->direct = _strdup(str);
	new->next = NULL;

	while (str[len] != '\0')
		len++;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new;

	return (new);
}