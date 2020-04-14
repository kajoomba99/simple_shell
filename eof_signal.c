#include "shell.h"

/**
 * handle_signal - the Signal Handler
 * @sig: Signal number.
 */

void handle_signal(int sig)
{
	write(1, "\n#cisfun$ ", 12);
	(void)sig;
}
