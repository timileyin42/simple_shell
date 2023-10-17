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
 * _help - show help document of some functions.
 * @h: node tha has the builtin command
 *
 * Return: no return
 */
int _help(bash_shell *h)
{
	char **argsearch = NULL;
	int x = 0, y = 0, entero = 0, l;
	char *args[] = {"cd", "env", "history", "exit", "alias", "help", "setenv",
			"unsetenv", NULL};
	char *filenames[] = {"h_cd.txt", "h_env.txt", "h_history.txt",
			     "h_exit.txt", "h_alias.txt", "h_help.txt",
			     "h_setenv.txt", "h_unsetenv.txt", NULL};
	int *posi = &x;
	char *pathandfile = NULL, *buffer = NULL, *filejusthelp = "justhelp.txt";

	argsearch = h->args;
	pathandfile = _calloc(500, 1);
	buffer = getpath();
	for (; buffer[l]; l++)
		pathandfile[l] = buffer[l];
	if (argsearch[1] == NULL)
	{
		justhelp(pathandfile, l, filejusthelp);
		return (0); }
	if (argsearch[1][0] == 0)
		return (0);
	while (args[x] != NULL)
	{
		entero = 0;
		for (; args[x][y] != '\0'; y++)
		{
			if (argsearch[1][y] - args[x][y] != 0)
			{
				entero = argsearch[1][y] - args[x][y];
				break; }}
		if (entero == 0)
			printhelp_text(filenames, posi, pathandfile);
		x++;
	}
	return (0);
}
