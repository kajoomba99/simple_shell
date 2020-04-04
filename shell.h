#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>

/*Signal fucntion*/
void handle_signal(int sig);
/*EOF function*/
void eof_func(char c);

#endif
