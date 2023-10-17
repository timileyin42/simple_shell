#include "holberton.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * imprimir_error - print error when command not found.
 * @h: node tha has the builtin command
 *
 * Return: no return
 */
void imprimir_error(bash_shell *h)
{
	int x = 0;
	char *sp = ": ";
	char *n = NULL;
	char *cont = NULL;
	char *com = NULL;
	char *msg = ": not found";
	char sl = '\n';
	int a = 127;

	com = h->args[0];
	cont = print_number(h->cont);
	n = h->name;
	x = _strlen(n);
	write(2, n, x - 1);
	write(2, sp, 2);
	x = _strlen(cont);
	write(2, cont, x - 1);
	write(2, sp, 2);
	x = _strlen(com);
	write(2, com, x - 1);
	x = _strlen(msg);
	write(2, msg, x - 1);
	write(2, &sl, 1);
	free(cont);
	setstatus(&a);
}
