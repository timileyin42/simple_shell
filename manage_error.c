#include "holberton.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * imprimir_errores_history - Function that print errors history.
 * @h: the list of elements
 *
 * Return: no return
 */
void imprimir_errores_history(bash_shell *h)
{
	int x = 0;
	char *sp = ": ";
	char *n = NULL;
	char *cont = NULL;
	char *com = NULL;
	char *msg = ": not found";
	char sl = '\n';
	int y = 2;

	com = h->args[0];
	cont = print_number(h->cont);
	n = h->name;
	x = _strlen(n);
	write(STDOUT_FILENO, n, x);
	write(STDOUT_FILENO, sp, 2);
	x = _strlen(cont);
	write(STDOUT_FILENO, cont, X);
	write(STDOUT_FILENO, sp, 2);
	x = _strlen(com);
	write(STDOUT_FILENO, com, x);
	x = _strlen(msg);
	write(STDOUT_FILENO, msg, x);
	write(STDOUT_FILENO, &sl, 1);
	free(cont);
	setstatus(&y);
}
/**
 * imprimir_errores_help - Function that help print errors
 * @h: the list of elements
 *
 * Return: no return
 */
void imprimir_errores_help(bash_shell *h)
{
	int x = 0;
	char *sp = ": ";
	char *n = NULL;
	char *cont = NULL;
	char *com = NULL;
	char *msg = ": not found";
	char sl = '\n';
	int y = 2;

	com = h->args[0];
	cont = print_number(h->cont);
	n = h->name;
	x = _strlen(n);
	write(STDOUT_FILENO, n, x);
	write(STDOUT_FILENO, sp, 2);
	x = _strlen(cont);
	write(STDOUT_FILENO, cont, x);
	write(STDOUT_FILENO, sp, 2);
	x = _strlen(com);
	write(STDOUT_FILENO, com, x);
	x = _strlen(msg);
	write(STDOUT_FILENO, msg, x);
	write(STDOUT_FILENO, &sl, 1);
	free(cont);
	setstatus(&y);
}
/**
 * imprimir_errores_cd - Function that adds a new node at the beginning
 * @h: pointer to head of the linked list
 *
 * return : no return
 */
void imprimir_errores_cd(bash_shell *h)
{
	int x = 0;
	char *sp = ": ";
	char *n = NULL;
	char *cont = NULL;
	char *com = NULL;
	char *msg = ": not found";
	char sl = '\n';
	int a = 2;

	com = h->args[0];
	cont = print_number(h->cont);
	n = h->name;
	x = _strlen(n);
	write(STDOUT_FILENO, n, x);
	write(STDOUT_FILENO, sp, 2);
	x = _strlen(cont);
	write(STDOUT_FILENO, cont, x);
	write(STDOUT_FILENO, sp, 2);
	x = _strlen(com);
	write(STDOUT_FILENO, com, x);
	x = _strlen(msg);
	write(STDOUT_FILENO, msg, x);
	write(STDOUT_FILENO, &sl, 1);
	free(cont);
	setstatus(&a);
}
