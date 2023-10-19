#include "main.h"

/**
 * free_pointer - Function frees a double pointer array of strings
 * (must end in NULL)
 *
 * @ptr: double pointer to free the buffer
 *
 * Return: no return
 */
void free_pointer(char **ptr)
{
	int x, y = 0;

	while (ptr[y] != 0)
		y++;

	for (x = 0; x < y; x++)
	{
		free(ptr[x]);
	}
	free(ptr);
}

/**
 * array_cpy - Function copies an array of strings (double pointer)
 *
 * @p: double pointer to copy
 * @old_size: original size of P
 * @new_size: size of copy
 *
 * Return: Pointer malloec
 */
char **array_cpy(char **p, int old_size, int new_size)
{
	char **copy;
	int x = 0, csize;

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
		for (; x < csize; x++)
		{
			copy[x] = _strdup(p[x]);
			if (copy[x] == 0)
			{
				x--;
				for (; x >= 0; x--)
					free(copy[x]);
				free(copy);
				return (0);
			}
		}

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
	int x = 0;

	if (s == NULL)
		return (0);

	while (s[x] != NULL)
		x++;
	return (x);
}
/**
 * _setenv - Function that overwrite an env variable or creates it
 *
 * @env: array of env variables
 * @variable: env variable to set
 * @value: value to set
 * @bash_s: struct with shell info
 *
 * Return: 0 on success, -1 on error
 */
char **_setenv(char **env, char *variable, char *value, bash *bash_s)
{
	int x, y, check, z = 0, lenv = 0;
	char *is_env, *to_env, *copydup, **copy;

	if (_strlen(variable) == 0 || variable == 0)
		return (error_fun(3, bash_s, 1), NULL);
	to_env = str_concat(variable, "=");
	if (to_env == 0)
		return (error_fun(3, bash_s, 1), NULL);
	is_env = str_concat(to_env, value), free(to_env);
	if (is_env == 0)
		return (error_fun(3, bash_s, 1), NULL);
	z = _strlen(variable), lenv = _strlendp(env);
	for (x = 0; env && env[x] != 0; x++)
	{
		for (check = 0, y = 0; y < z && env[x][y] != 0; y++)
		{
			if (variable[y] == '=')
				return (free(is_env), error_fun(3, bash_s, 2), NULL);
			if (env[x][y] == variable[y])
				check++;
		}
		if (check == z && env[x][check] == '=')
		{
			free(env[x]), copydup = _strdup(is_env), free(is_env);
			if (copydup == 0)
				return (error_fun(3, bash_s, 1), NULL);
			return (env[x] = copydup, env);
		}
	}
	copy = array_cpy(env, lenv, lenv + 1);
	if (env)
		free_pointer(env);
	if (copy == 0)
		return (free(is_env), error_fun(3, bash_s, 1), NULL);
	env = copy, copydup = _strdup(is_env), free(is_env);
	if (copydup == 0)
		return (error_fun(3, bash_s, 1), NULL);
	return (env[lenv] = copydup, env);
}
