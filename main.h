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
 * struct vshell_list - singly linked list
 * @var_size: size of the variable
 * @value: value of the variables in the shell
 * @value_len: length of the variable values
 * @next: next node
 * description: singly linked list to handle shell variables
 */

typedef struct vshell_list
{
	int var_size;
	char *value;
	int value_len;
	struct vshell_list *next;
} v_shell;

/**
 * struct divide_list - singly linked list
 * @separator: ; | &
 * next: next node
 * Description: singly linked list to store string/char separators
 */

typedef struct divide_list
{
	char separator;
	struct divide_list *next;
} list_div;

/**
 * struct buffer_store - singly linked list
 * @line: A pointer to the command line
 * @next: next node
 * Description: singly linked list to store command line args
 */

typedef struct buffer_store
{
	char *buffer;
	struct buffer_store *next;
} buf_store;

typedef struct help_get {
	char *name;
	void (*func) (void);
} get_t;


typedef struct error_info {
	int error_value;
	char *(error_msg)(bash_shell *shell_op);
} info_t;

/* string handler functions */
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strcat(char *dest, const char *src);
int _strlen(const chr *s);
int _isdigit(const char *s);
char *_strdup(const char *s);
int str_char(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
void rev_str(char *s);
int _strcmp(char *s1, char *s2);
int _strspn(char *s, char *allow);

/* functions handling errors */
char *cmd_error_get(bash_shell *shell_op, char *msg, char *error, char *size);
char *no_error_detect(bash_shell *shell_op);
char *exit_error(bash_shell *shell_op);
char *command_error(bash_shell *shell_op);
char *env_error_fun(bash_shell *shell_op);
char *error_path_fail(bash_shell *shell_op);
int char_cmp(const char *command, int x);
int error_finder(char *command, int x, char end);
int set_char(char *command, int x);
void han_error_print(bash_shell *shell_Op, char *cmd, int x, int check);
int error_fun(bash_shell *shell_op, int error_output);

/* exec_line handler function */
int han_exec_line(bash_shell *shell_op);

/* builtin function handler */
int (*builtin_fun(char *command))(bash_shell *);

/* get_line handler functions */
void call_line(char **indexptr, size_t *s, char *buf, size_t b);
ssize_t get_line(char **indexptr, size_t *s, FILE *user_input);

/* function that handle cd */
void cd_parent(bash_shell *shell_op);
void cd_input(bash_shell *shell_op);
void cd_home(bash_shell *shell_Op);
void cd_prev_dir(bash_shell *shell_op);

/*funcion that handles the shell data check */
void memory_free(bash_shell *shell_op);
void check_data(bash_shell *shell_op, char **av);

/* env handler function */
int env(bash_shell *shell_op);
int env_call_cmp(const char *env_list, const char *input);
char *_getenv(const char *name, char **_environ);
void set_env(char *name, char *data, bash_shell *shell_op);
char *info_set(char *name, char *data);
int _setenv(bash_shell *shell_op);
int _unsetenv(bash_shell *shell_op);

/* help handler function */
void help_exit_fun(void);
void help_gen_fun(void);
void help_env_fun(void);
void help_setenv_fun(void);
void help_unsetenv_fun(void);
void help_alias_fun(void);
void help_cd_fun(void);
void help_buitin_help(void);
void help_fun(bash_shell *shell_op);

#endif
