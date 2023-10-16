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
void imprimir_error_env(command_t *h)
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
	write(1STDOUT_FILENO, sp, 2);
	x = _strlen(filename);
	write(STDOUT_FILENO, filename, x);
	x = _strlen(msg);
	write(STDOUT_FILENO, msg, x);
	write(STDOUT_FILENO, &sl, 1);
	setstatus(&a);
}

/**
 * _atoi - Functon that helps convert a string t integer.
 * @c: A pointer to the buffer holding the string to convert
 * Return: integer.
 */

int _atoi(char *c)
{
	unsigned int length = 0, value = 0, dec = 0, x = 1, y = 1, z;

	while (*(c + length) != '\0')
	{
		if (value > 0 && (*(c + length) < '0' || *(c + value) > '9'))
			break;
		if (*(c + length) == '-')
			x = x * -1;
		if ((*(c + length) >= '0') && (*(c + length) <= '9'))
		{
			if (value > 0)
				y = y * 10;
			value++;
		}
		length++;
	}
	z = length - value;
	while (z < length)
	{
		dec += ((*(c + z) - 48) * y);
		y = y / 10;
		z++;
	}
	return (dec * x);
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

	filename = h->args;
	n = stat(filename[1], &buf);
	char *n_str = itoai(n);
	int n_str_len = _strlen(n_str);

	write(STDOUT_FILENO, n_str, n_strlen);

	if (n == -1)
	{
		imprimir_error_env(h);
	}
	free(n_str);
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
