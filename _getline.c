#include "shell.h"

/**
 * _getline - Reads an entire line from stream.
 * @lineptr: Storing the address of the buffer containing the text into.
 * Return: Number of characters.
 */
size_t _getline(char **lineptr)
{
	int size = 1024;
	size_t input_l = 0;
	char *b = *lineptr;

	if (*lineptr == NULL)
	{
		write(STDOUT_FILENO, "Line empty\n", 12);
		return (-1);
	}

	do {
		fflush(stdout);
		input_l = read(STDIN_FILENO, *lineptr, size);
		if (input_l < 1)
		{
			*lineptr = b;
			return (-1);
		}
		if ((*lineptr)[input_l - 1] == '\n' && input_l == 1)
		{
			*lineptr = b;
			int b_len = _strlen(b);

			if (b_len > 1)
				return (b_len);
			return (0);
		}
		if ((*lineptr)[input_l - 1] != '\n' && input_l >= 1)
			*lineptr += input_l;
		if (input_l >= 1)
		{
			lineptr[input_l - 1] = '\0';
			*lineptr = b;
			return (input_l);
		}
	} while (1);

	return (input_l);
}
