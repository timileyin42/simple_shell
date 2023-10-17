#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * free_doubpoint - frees a double pointer array of strings
 * (must end in NULL)
 *
 * @p: double pointer to free
 *
 * Return: no return
 */
void free_doubpoint(char **p)
{
	int i, l = 0;

	while (p[l] != 0)
		l++;

	for (i = 0; i < l; i++)
	{
		free(p[i]);
	}
	free(p);
}
/**
 * _copydoublep - copies an array of strings (double pointer)
 *
 * @p: double pointer to copy
 * @old_size: original size of P
 * @new_size: size of copy
 *
 * Return: Pointer malloec
 */
char **_copydoublep(char **p, int old_size, int new_size)
{
	char **copy;
	int i, csize;

	if (!p && (old_size == new_size))
		return (NULL);

	if (new_size < old_size)
	{
		csize = new_size;
		copy = malloc(sizeof(char *) * (csize + 1));
	}
	else
	{
		csize = old_size;
		copy = malloc(sizeof(char *) * (new_size + 1));
	}
	if (copy == 0)
		return (0);

	if (p)
		for (i = 0; i < csize; i++)
		{
			copy[i] = _strdup(p[i]);
			if (copy[i] == 0)
			{
				i--;
				for (; i >= 0; i--)
					free(copy[i]);
				free(copy);
				return (0);
			}
		}

	/* Add Null in the end */
	copy[new_size] = '\0';

	return (copy);
}
/**
 * _strlendp - calculates length of double pointer (ending in NULL)
 * @s: double pointer
 *
 * Return: Length of double pointer
 *
 */
int _strlendp(char **s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i] != NULL)
		i++;
	return (i);
}
/**
 * _setenv - overwrite an env variable or creates it
 *
 * @env: array of env variables
 * @variable: env variable to set
 * @value: value to set
 * @shpack: struct with shell info
 *
 * Return: 0 on success, -1 on error
 */
char **_setenv(char **env, char *variable, char *value, hshpack *shpack)
{
	int i, j, check, l = 0, lenv = 0;
	char *envjoin, *envjoin2, *copydup, **copy;

	if (_strlen(variable) == 0 || variable == 0)
		return (_error(3, shpack, 1), NULL);
	envjoin2 = str_concat(variable, "=");
	if (envjoin2 == 0)
		return (_error(3, shpack, 1), NULL);
	envjoin = str_concat(envjoin2, value), free(envjoin2);
	if (envjoin == 0)
		return (_error(3, shpack, 1), NULL);
	l = _strlen(variable), lenv = _strlendp(env);
	for (i = 0; env && env[i] != 0; i++)
	{
		for (check = 0, j = 0; j < l && env[i][j] != 0; j++)
		{
			if (variable[j] == '=')
				return (free(envjoin), _error(3, shpack, 2), NULL);
			if (env[i][j] == variable[j])
				check++;
		}
		if (check == l && env[i][check] == '=')
		{
			free(env[i]), copydup = _strdup(envjoin), free(envjoin);
			if (copydup == 0)
				return (_error(3, shpack, 1), NULL);
			return (env[i] = copydup, env);
		}
	}
	copy = _copydoublep(env, lenv, lenv + 1);
	if (env)
		free_doubpoint(env);
	if (copy == 0)
		return (free(envjoin), _error(3, shpack, 1), NULL);
	env = copy, copydup = _strdup(envjoin), free(envjoin);
	if (copydup == 0)
		return (_error(3, shpack, 1), NULL);
	return (env[lenv] = copydup, env);
}
