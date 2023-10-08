#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <signal.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;


/**
 * struct bash - structure that contains all relevant data on runtime
 * @av: argument vector
 * @code: command line code blocks written by the user
 * @args: tokens of the command line
 * @mode: the mode of the shell
 * @count: the total lines count in the shell
 * @_environ: environment variable
 * @pid: The process ID of the shell
 */

typedef struct bash
{
	char **av;
	char *code;
	char **args;
	int mode;
	int count;
	char **environ;
	char *pid;
} bash_shell;

/**
 * struct builtin_f - Builtin struct for command args.
 * @command: The command builtin name i.e cd, exit, env
 * @s: A pointer to the data type
 */

typedef struct builtin_f
{
	char *name;
	int (*s)(bash_shell *shell_op);
} get_builtin;

/**
 * struct vshell_list - single linked list
 * @var_size: size of the variable
 * @value: value of the variables in the shell
 * @value_len: length of the variable values
 * @next: next node
 * description: single linked list to handle shell variables
 */

typedef struct vshell_list
{
	int var_size;
	char *value;
	int value_len;
	struct vshell_list *next;
} v_shell;

#endif
