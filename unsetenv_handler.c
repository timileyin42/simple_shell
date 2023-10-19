#include "main.h"

/**
 * double_cp - Function copies an array of strings (double pointer)
 *
 * @p: double pointer to copy
 * @new_size: size of copy
 * @jump: value that must be skipped in copy
 *
 * Return: Pointer malloec
 */
char **double_cp(char **p, int new_size, int jump)
{
	char **copy;
	int x, y, csize;

	csize = new_size;
	copy = malloc(sizeof(char *) * (csize + 1));
	if (copy == 0)
		return (0);

	for (x = 0, y = 0; y < csize; x++, y++)
	{
		if (x == jump)
			x++;
		copy[y] = _strdup(p[x]);
		if (copy[y] == 0)
		{
			y--;
			for (; y >= 0; y--)
				free(copy[y]);
			free(copy);
			return (0);
		}
	}

	copy[new_size] = '\0';

	return (copy);
}

/**
 * unsetenv_fun - unsets an enviromental variable
 *
 * @env: array of env variables
 * @variable: env variable to unset
 * @bash_s: struct with shell info
 *
 * Return: 0 on success, -1 on error
 */
char **unsetenv_fun(char **env, char *variable, bash *bash_s)
{
	int x, y, check, z = 0, lenv = 0, found = 0;
	char **copy;

	bash_s->unsetnull[0] = 0;
	if (env == NULL)
		return (write(STDERR_FILENO, "Environment is NULL\n", 20), NULL);
	if (_strlen(variable) == 0 || variable == 0)
		return (error_fun(3, bash_s, 1), NULL);
	z = _strlen(variable), lenv = _strlendp(env);
	for (x = 0; env[x] != 0; x++)
	{
		for (check = 0, y = 0; y < z && env[z][y] != 0; y++)
		{
			if (variable[y] == '=')
				return (error_fun(3, bash_s, 2), NULL);
			if (env[x][y] == variable[y])
				check++;
		}
		if (check == z && env[x][check] == '=')
		{
			found = 1;
			if ((lenv - 1) != 0)
			{
				copy = double_cp(env, lenv - 1, x);
				if (copy == 0)
					return (error_fun(7, bash_s, 1), NULL);
			}
			else
				bash_s->unsetnull[0] = 1, copy = NULL;
			free_pointer(env), env = copy;
			return (env);
		}
	}
	if (found == 0)
		return (write(STDERR_FILENO, "VARIABLE not found\n", 19), NULL);
	return (env);
}
