#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef struct directories
{
	char *direct;
	struct directories *next;
} directs;

char *_which(directs **head, char *dir);
char *_getenv(const char *name);
void add_dir_to_struct(struct directories **head, char *directories);
struct directories *add_node_end(struct directories **head, const char *str);
char **put_args(char **av, char *str);
char *_strcat(char *fstr, char *sstr);
char **flags(char **args);
int _strlen(char *str);
int count_args(char **arr);
char **sep_by_space(char *str);
char **get_params(char **args);
int start_func(char *line);

#endif
