#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>

extern char **environ;
/*Signal fucntion*/
void handle_signal(int sig);
/*EOF function*/
void eof_func(char c);

/**
 * struct directories - struct directories
 * @direct: direct
 * @next: next
 */
typedef struct directories
{
	char *direct;
	struct directories *next;
} directs;

struct directories *add_node_end(struct directories **head, const char *str);
void add_dir_to_struct(struct directories **head, char *directories);
void put_stuff_in_dbl(char **dbl, char **stuff);
char *_which(directs **head, char *dir);
char **put_args(char **av, char *str);
char *_strcat(char *fstr, char *sstr);
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
char *add_one_to_env(char *ern);
char **sep_by_space(char *str);
char **get_params(char **args);
char *_strdup(const char *str);
void error_printer(char *file);
void free_dbl_arr(char **arr);
void free_list(directs *head);
int count_args(char **arr);
int start_func(char *line);
char **flags(char **args);
void exect_prompt(void);
int _strlen(char *str);
int env(void);

#endif
