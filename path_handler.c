#include "main.h"

/**
 * _pathcheck - check if current dir must be added
 * @path: path env variable
 *
 * Return: Pointer to adress of new PATH
 *
 */

char *path_han(char *path)
{
	char *npath;
	int x, y, nsize, count = 0;

	for (x = 0; path[x]; x++)
	{

		if (path[x] == '=' && path[x + 1] == ':')
			count++;
		if (path[x] == ':' && path[x + 1] == ':')
			count++;
		if (path[x] == ':' && path[x + 1] == '\0')
			count++;
	}
	if (count == 0)
		return (0);
	nsize = _strlen(path) + 1 + count;
	npath = malloc(sizeof(char) * nsize);

	for (x = 0, y = 0; x < nsize; x++, y++)
	{
		if (path[y] == '=' && path[y + 1] == ':')
		{
			npath[x] = path[y], npath[x + 1] = '.', x++;
			continue;
		}
		if (path[y] == ':' && path[y + 1] == ':')
		{
			npath[x] = path[y], npath[x + 1] = '.', x++;
			continue;
		}
		if (path[y] == ':' && path[y + 1] == '\0')
		{
			npath[x] = path[y], npath[x + 1] = '.', x++;
			continue;
		}
		npath[x] = path[y];
	}
	free(path);
	return (npath);
}
/**
 * _path - Searches for a cmd in PATH
 * @cmd: string contating env variable PATH
 * @env: current environment
 * @bash_s: struct containing shell info
 *
 * Return: Pointer to adress of cmd in PATH or by itself
 *
 */

char *path_fun(char *cmd, char **env, bash *bash_s)
{
	char *path, *path2;
	struct stat st;
	char *token, *concat, *concat2, *pathcheck, *delim = ":=";
	int x;

	for (x = 0; cmd[x]; x++)
		if (cmd[x] == '/' || cmd[x] == '|')
		{
			if (stat(cmd, &st) == 0)
				return (concat = str_concat(cmd, '\0'));
			else
				return (0);
		}

	path2 = _getenv("PATH", env);
	(void) bash_s;
	if (path2 == NULL)
		return (0);
	path = _strdup(path2);
	pathcheck = path_han(path);
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
