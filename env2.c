#include "holberton.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX 500

/**
 * setstatus - set status.
 * @stat: pointer to status
 *
 * Return: number of status
 */
int setstatus(int *stat)
{
	static int status;

	if (stat)
		status = *stat;
	return (status);
}
/**
 * look - search for a builtin.
 * @fun: command to compare with builtins
 *
 * Return: 1 if there is a builtin or 0 if it is not
 */
int look(char *fun)
{
	int pos = 0, flag = 0, x = 0;
	char *current = NULL;
	char *built[] =  {"history", "exit", "env", "help", "cd", "setenv",
			  "unsetenv", "alias", NULL};

	while (built[x])
	{
		current = built[x];
		for (pos = 0; current[pos] && fun[pos]; pos++)
		{
			if (current[pos] == fun[pos])
			{
				if (current[pos + 1] == 0 && fun[pos + 1] == 0)
					return (BUILT);
			}
			else
				break;
		}
		x++;
	}
	return ((flag == 0) ? EXT : BUILT);
}

/**
 * currentpath - obtein current path.
 *
 * Return: pointer to the current path
 */
char *currentpath(void)
{
	int x = 0;
	char *py = _calloc(MAX, MAX);

	getcwd(py, MAX);
	for (; py[x]; x++)
		;
	py[x] = '/';
	x++;
	py[x] = 0;
	return (py);
}

/**
 * numdirectories - count number of directories in the path.
 * @path: value of variable PATH
 *
 * Return: number of directories
 */
int numdirectories(char *path)
{
	int sp = 0, x = 0;

	for (; path[x]; x++)
		if (path[x] == ':')
			sp++;
	if (path[0] != 0)
		sp++;
	return (sp);
}
