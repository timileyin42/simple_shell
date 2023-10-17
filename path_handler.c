#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * _pathcheck - check if current dir must be added
 * @path: path env variable
 *
 * Return: Pointer to adress of new PATH
 *
 */

char *_pathcheck(char *path)
{
	char *npath;
	int i, j, nsize, count = 0;

	for (i = 0; path[i]; i++)
	{

		if (path[i] == '=' && path[i + 1] == ':')
			count++;
		if (path[i] == ':' && path[i + 1] == ':')
			count++;
		if (path[i] == ':' && path[i + 1] == '\0')
			count++;
	}
	if (count == 0)
		return (0);
	nsize = _strlen(path) + 1 + count;
	npath = malloc(sizeof(char) * nsize);

	for (i = 0, j = 0; i < nsize; i++, j++)
	{
		if (path[j] == '=' && path[j + 1] == ':')
		{
			npath[i] = path[j], npath[i + 1] = '.', i++;
			continue;
		}
		if (path[j] == ':' && path[j + 1] == ':')
		{
			npath[i] = path[j], npath[i + 1] = '.', i++;
			continue;
		}
		if (path[j] == ':' && path[j + 1] == '\0')
		{
			npath[i] = path[j], npath[i + 1] = '.', i++;
			continue;
		}
		npath[i] = path[j];
	}
	free(path);
	return (npath);
}
/**
 * _path - Searches for a cmd in PATH
 * @cmd: string contating env variable PATH
 * @env: current environment
 * @shpack: struct containing shell info
 *
 * Return: Pointer to adress of cmd in PATH or by itself
 *
 */

char *_path(char *cmd, char **env, hshpack *shpack)
{
	char *path, *path2;
	struct stat st;
	char *token, *concat, *concat2, *pathcheck, *delim = ":=";
	int i;

	for (i = 0; cmd[i]; i++)
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (concat = str_concat(cmd, '\0'));
			else
				return (0);
		}

	path2 = _getenv("PATH", env);
	(void) shpack;
	if (!path2)
		return (0);
	path = _strdup(path2);
	pathcheck = _pathcheck(path);
	if (pathcheck)
		path = pathcheck;
	token = _strtok(path, delim);
	for (token = _strtok(0, delim); token; token = _strtok(0, delim))
	{
		concat = str_concat(token, "/");
		concat2 = str_concat(concat, cmd);
		free(concat);
		if (stat(concat2, &st) == 0)
		{
			/*Found the command in PATH*/
			free(path);
			return (concat2);
		}
		free(concat2);
	}

	free(path);
	return (0);
}
