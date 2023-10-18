#include "main.h"

/**
 * path_han - check if current dir must be added
 * @path: path env variable
 *
 * Return: Pointer to adress of new PATH
 *
 */

char *path_han(char *path)
{
	char *n_path;
	int x, y, p_size, count = 0;

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
	p_size = _strlen(path) + 1 + count;
	n_path = malloc(sizeof(char) * p_size);

	for (x = 0, y = 0; x < p_size; x++, y++)
	{
		if (path[y] == '=' && path[y + 1] == ':')
		{
			n_path[x] = path[y], n_path[x + 1] = '.', x++;
			continue;
		}
		if (path[y] == ':' && path[y + 1] == ':')
		{
			n_path[x] = path[y], n_path[x + 1] = '.', x++;
			continue;
		}
		if (path[y] == ':' && path[y + 1] == '\0')
		{
			n_path[x] = path[y], n_path[x + 1] = '.', x++;
			continue;
		}
		n_path[x] = path[y];
	}
	free(path);
	return (n_path);
}
/**
 * path_fun - Searches for a cmd in PATH
 * @cmd: string contating env variable PATH
 * @env: current environment
 * @bash_s: struct containing shell info
 *
 * Return: Pointer to adress of cmd in PATH or by itself
 *
 */

char *path_fun(char *cmd, char **env, bash *bash_s)
{
	char *path, *to_path;
	struct stat st;
	char *token, *is_concat, *to_concat, *pathcheck, *delim = ":=";
	int x = 0;

	for (; cmd[x]; x++)
		if (cmd[x] == '/' || cmd[x] == '|')
		{
			if (stat(cmd, &st) == 0)
				return (is_concat = str_concat(cmd, '\0'));
			else
				return (0);
		}

	to_path = _getenv("PATH", env);
	(void) bash_s;
	if (to_path == NULL)
		return (0);
	path = _strdup(to_path);
	pathcheck = path_han(path);
	if (pathcheck)
		path = pathcheck;
	token = _strtok(path, delim);
	for (token = _strtok(0, delim); token; token = _strtok(0, delim))
	{
		is_concat = str_concat(token, "/");
		to_concat = str_concat(is_concat, cmd);
		free(is_concat);
		if (stat(to_concat, &st) == 0)
		{
			free(path);
			return (to_concat);
		}
		free(to_concat);
	}

	free(path);
	return (0);
}
