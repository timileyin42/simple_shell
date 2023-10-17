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
 * _history - show history of commands.
 * @h: node tha has the builtin command
 *
 * Return: no return
 */
int _history(bash_shell *h)
{
	char *message = "shell history\n";
	(void)h;

	write(STDOUT_FILENO, message, _strlen(message));
	return (0);
}

/**
 * justhelp - show help document of some functions.
 * @pathandfile: node tha has the builtin command
 * @l: integer
 * @filejusthelp: name of file
 *
 * Return: no return
 */
int justhelp(char *pathandfile, int l, char *filejusthelp)
{

	int k, longbuf = 0;
	char *buf = NULL;
	ssize_t a = 0;
	ssize_t *p = &a;

	pathandfile[l] = '/';
	l++;
	for (k = 0; k < 12; k++, l++)
		pathandfile[l] = filejusthelp[k];
	buf = _getline(p, pathandfile);
	longbuf = _strlen(buf);
	write(1, buf, longbuf);
	free(pathandfile);
	free(buf);
	return (0);
}

/**
 * printhelp_text - print document of help.
 * @filenames: node tha has the builtin command
 * @posi: posición filename
 * @pathandfile: current path static.
 *
 * Return: no return
 */

void printhelp_text(char **filenames, int *posi, char *pathandfile)
{
	int aux = *posi;
	int j, g, k, longbuf;
	char *buf;
	ssize_t a = 0;
	ssize_t *p = &a;

	for (j = 0; filenames[aux][j] != 0; j++)
		;
	for (g = 0; pathandfile[g]; g++)
		;
	pathandfile[g] = '/';
	g++;
	for (k = 0; k < j; k++, g++)
		pathandfile[g] = filenames[aux][k];
	buf = _getline(p, pathandfile);
	longbuf = _strlen(buf);
	write(1, buf, longbuf);
	free(pathandfile);
	free(buf);
}
