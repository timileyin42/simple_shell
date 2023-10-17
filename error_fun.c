#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#define MAX 500

/**
 * imprimir_error_env - print errors env builtin.
 * @h: the list of elements
 *
 * Return: direction of the new node
 */
void imprimir_error_env(bash_shell *h)
{
	int x = 0;
	char *sp = ": ";
	char *com = NULL;
	char *filename = NULL;
	char *msg = ": No such file or directory";
	char sl = '\n';
	int a = 127;

	com = h->args[0];
	filename = h->args[1];
	x = _strlen(com);
	write(STDOUT_FILENO, com, x);
	write(STDOUT_FILENO, sp, 2);
	x = _strlen(filename);
	write(STDOUT_FILENO, filename, x);
	x = _strlen(msg);
	write(STDOUT_FILENO, msg, x);
	write(STDOUT_FILENO, &sl, 1);
	setstatus(&a);
}

/**
 * search_file_env - search file name.
 * @h: the list of elements
 *
 * Return: o or -1 if it fails
 */
int search_file_env(bash_shell *h)
{

	char **filename = NULL;
	int n = 0;
	struct stat buf;
	char str[50];

	filename = h->args;
	n = stat(filename[1], &buf);
	sprintf(str,"%d", n);
	write(STDOUT_FILENO, str, _strlen(str));
	if (n == -1)
		imprimir_error_env(h);
	return (0);
}

/**
 * imprimir_error_setenv - print error setenv
 * @h: the list of elements
 *
 * Return: no return
 */
void imprimir_error_setenv(bash_shell *h)
{
	int x = 0;
	char *sp = ": ";
	char *com = NULL;
	char *variable = NULL;
	char *msg = ": Variable not found";
	char sl = '\n';
	int y = 1;

	com = h->args[0];
	variable = h->args[1];
	x = _strlen(com);
	write(STDOUT_FILENO, com, x);
	write(STDOUT_FILENO, sp, 2);
	x = _strlen(variable);
	write(STDOUT_FILENO, variable, x);
	x = _strlen(msg);
	write(STDOUT_FILENO, msg, x);
	write(STDOUT_FILENO, &sl, 1);
	setstatus(&y);
}

/**
 * imprimir_error_unsetenv - print unsetenv errors
 * @h: pointer ti the head of the linked list
 *
 * Return: no return
 */
void imprimir_error_unsetenv(bash_shell *h)
{
	int x = 0;
	char *sp = ": ";
	char *com = NULL;
	char *variable = NULL;
	char *msg = ": Variable not found";
	char sl = '\n';
	int y = 1;

	com = h->args[0];
	variable = h->args[1];
	x = _strlen(com);
	write(STDOUT_FILENO, com, x);
	write(STDOUT_FILENO, sp, 2);
	x = _strlen(variable);
	write(STDOUT_FILENO, variable, x);
	x = _strlen(msg);
	write(STDOUT_FILENO, msg, x);
	write(STDOUT_FILENO, &sl, 1);
	setstatus(&y);
}
