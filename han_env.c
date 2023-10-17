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
 * _env - show all environment variables.
 * @h: node tha has the builtin command
 *
 * Return: no return
 */
int _env(bash_shell *h)
{
	char **env = NULL, **args = NULL;
	int x = 0, y = 0;
	char sl = '\n';

	(void)h;
	args = h->args;
	if (args[1] != NULL)
	{
		search_file_env(h);
		return (0);
	}
	env = _setenv(NULL, NULL);
	while (env[x])
	{
		for (y = 0; env[x][y]; y++)
			;
		write(STDOUT_FILENO, env[x], y);
		write(STDOUT_FILENO, &sl, 1);
		x++;
	}
	return (0);
}

/**
 * _setenviron - set environ.
 * @h: node tha has the builtin command
 *
 * Return: o if succes or -1
 */
int _setenviron(bash_shell *h)
{
	char **args = NULL;
	int x = 0, st = 0;

	args = h->args;
	for (; args[x]; x++)
		;
	if (x != 3)
	{
		setstatus(&st);
		return (0);
	}
	_setenv(args[1], args[2]);
	setstatus(&st);
	return (0);
}

/**
 * _unsetenv - unset variable.
 * @h: node tha has the builtin command
 *
 * Return: no return
 */
int _unsetenv(bash_shell *h)
{
	char **args = NULL;
	char *var = NULL;
	char *err = "Error\n";
	int x = 0;

	args = h->args;
	for (; args[x]; x++)
		;
	if (x != 2)
	{
		write(2, err, _strlen(err));
		return (-1);
	}
	var = _getenvvar(args[1]);
	if (var)
	{
		_setenv(args[1], NULL);
		free(var);
		return (0);
	}
	else
	{
		write(2, err, _strlen(err));
		return (-1);
	}
	return (-1);
}
