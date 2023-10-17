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
 * getvaderdir - get variable directory.
 *
 * Return: no return
 */
char  *getvaderdir(void)
{
	int y = 0, x = 0;
	char *pwd = NULL;
	char *newpwd = NULL;

	pwd = _getenvvar("PWD");
	for (; pwd[y]; y++)
		if (pwd[y] == '/')
			x = y;
	newpwd = _calloc(x + 2, sizeof(char));
	for (y = 0; pwd[y] && y < x; y++)
		newpwd[y] = pwd[y];
	free(pwd);
	return (newpwd);
}

/**
 * chtopreviousdir - give previous directory.
 *
 * Return: no return
 */
int chtopreviousdir(void)
{
	char *oldpwd = NULL;
	char *pwd = NULL;
	DIR *dir = NULL;
	int x = 0;
	char sl = '\n';

	oldpwd = _getenvvar("OLDPWD");
	pwd = _getenvvar("PWD");
	if (!oldpwd)
	{
		write(STDOUT_FILENO, "OLDPWD not set error", 21);
		free(pwd);
		return (-1);
	}
	else
	{
		dir = opendir(oldpwd);
		if (dir == NULL)
		{
			write(STDOUT_FILENO, "ERROR\n", 6);
			return (-1);
		}
		closedir(dir);
		chdir(oldpwd);
		_setenv("OLDPWD", pwd);
		for (; oldpwd[x]; x++)
			;
		write(STDOUT_FILENO, oldpwd, x);
		write(STDOUT_FILENO, &sl, 1);
		free(pwd);
		free(oldpwd);
		return (0);
	}
	return (-1);
}

/**
 * dirandcommand - add command to the directory of the path.
 * @crtdir: each directory
 * @aux: pointer to the filename
 * @com: command and arguments
 *
 * Return: pointer to the etotal path of the directory
 */
char *dirandcommand(char *crtdir, char *aux, char *com)
{

	int x, y;

	for (x = 0; crtdir[x]; x++)
		aux[x] = crtdir[x];
	for (y = 0; com[y]; y++, x++)
		aux[x] = com[y];
	aux[x] = 0;
	return (aux);
}

/**
 * darthVader - change directory father.
 *
 * Return: return 0
 */
int darthVader(void)
{
	char *newpwd = NULL;
	char *pwd = NULL;
	DIR *dir = NULL;
	char error_msg[] = "Error : 'v \n";

	pwd = _getenvvar("PWD");
	newpwd = getvaderdir();
	dir = opendir(newpwd);

	if (dir == NULL)
	{
		write(STDOUT_FILENO, error_msg, _strlen(error_msg));
		free(pwd);
		free(newpwd);
		return (-1);
	}
	closedir(dir);
	chdir(newpwd);
	_setenv("PWD", newpwd);
	_setenv("OLDPWD", pwd);
	free(pwd);
	free(newpwd);
	return (0);
}

/**
 * nextdir - give next dire after .. /.
 * @filter: pointer to buffer
 * @buf: position before directory
 * Return: position of the next dir or -1
 */
int nextdir(char *filter, int buf)
{
	if (!filter[buf])
		return (-1);
	buf++;
	for (; filter[buf]; buf++)
		if (filter[buf] == '/')
			return (buf);
	return (-1);
}
