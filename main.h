#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <signal.h>
#include <limits.h>
#include <stddef.h>
#include <sys/wait.h>

/**
 * struct bash - struct containing important shell info
 * @hshname: name of the shell (argv[0])
 * @buffer: full buffer written in prompt
 * @cmd: command written after prompt
 * @options: options of the command
 * @path: path of the cmd if found, else cmd itself
 * @errnum: error count
 * @exitnum: number of exit that the shell will have
 * @relation: true or false for logical operators
 * @run_able: check for running or not a command
 * @next: singly list link
 * @envCpy: copy of environment
 * @unsetnull: check for setting environment to NULL
 *
 * Description: Struct containing important shell info
 *
 */
typedef struct bash
{
	char *hshname;        /* Name of shell argv[0] */
	char *buffer;         /* complete line written in prompt */
	char *cmd;            /* current command */
	char **options;       /* options of current command */
	char *path;           /* absolute path of command */
	int *errnum;          /* error number for message */
	int *exitnum;         /* exit number */
	int *relation;        /* 0 Undef, 1 ||, 2 && */
	int *run_able;        /* 0 False 1 True (Is able to run)*/
	struct bash *next; /*adress of next cmd to run */
	char ***envCpy;       /* current environment */
	int *unsetnull;       /*check for setting environment to NULL */

} bash;

/**
 * struct b_ins - struct for built ins
 * @cmd: built in
 * @f: function of built in
 *
 * Description: Struct for calling built in functions
 *
 */
typedef struct b_ins
{
	char *cmd;
	ssize_t (*f)(bash *bash_s);
} b_ins;

/**
 * struct Helps - struct for built ins
 * @built: built in command
 * @h: help function of built in
 *
 * Description: Struct for calling built in functions
 *
 */
typedef struct Helps
{
	char *built;
	void (*h)(void);
} helps;


char *han_cd(bash *bash_s, char *currdir);
char *cd_home(bash *bash_s, char __attribute__((unused)) *currdir);
char *_getenv(const char *name, char **env);
char *path_fun(char *cmd, char **env, bash *bash_s);
char *path_han(char *path);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, const char *delim);
char **getParameters(char *buffer, bash *bash_s);
int exec_cmd(char *program, char *command[], char **env, bash *bash_s);
void signal_handler(int __attribute__((unused)) x);
void signal_handler2(int __attribute__((unused)) x);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _getline(char **buffer, size_t *bufsize, int fd);
void free_doubpoint(char **p);
char **array_cpy(char **p, int old_size, int new_size);
int _strlendp(char **s);
char **shell_cmd(int ac, char **av, size_t *bufsize,
		  char **buffer, bash *bash_s);
bash *set_struct(char *argv0, int *errn, int *exnum, int *relation,
		    int *run_able, char ***env, int *unsetnull);
int _error(int errn, bash *bash_s, int exnum);
void addCmd(bash *bash_s, char *buffer, char *command, char **parameters);
void addPathToCmd(bash *bash_s, char *pathCmd);
ssize_t built_ints(bash *bash_s);
ssize_t shell_exit(bash *bash_s);
ssize_t shell_env(bash *bash_s);
ssize_t shell_setenv(bash *bash_s);
ssize_t shell_unsetenv(bash *bash_s);
int _strcmp(char *s1, char *s2);
long _atoi(char *s);
long _pow(long base, long pos);
char **double_cp(char **p, int old_size, int new_size);
int _strlendp(char **s);
char **_setenv(char **env, char *variable, char *value, bash *bash_s);
char **_unsetenv(char **env, char *variable, bash *bash_s);
int _isdigit(int c);
int _isnumber(char *s);
ssize_t cd_cmd(bash *bash_s);
char *deleteComment(char *str);


ssize_t _help_cmd(bash *bash_s);
void write_buf(char *s);
void help_unsetenv(void);
void help_cd(void);
void help_help(void);
void help_alias(void);
void printsHelp(void);

#endif
