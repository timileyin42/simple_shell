#include "main.h"

/**
 * _env - Functions that helps prints the environment variables
 * @shell_op: A pointer to the data relevant structure.
 * Return: 1 on success.
 */

int _env(bash_shell *shell_op)
{
	int x, y;

	while (shell_op->_environ[x] != NULL)
	{
		int x = 0;

		while (shell_op->_environ[x][y] != '\0')
		{
			x++;
		}

		write(1, shell_op->_environ[x], y);
		write(1, "\n", 1);

		x++;
	}

	shell_op->mode = 0;

	return (1);
}

/**
 * env_call_cmp - Functions that helps compares the environment var names with
 * the one input
 * @env_list: A pointer to the name of environment variable
 * @input: A pointer to the name of variable passed
 * Return: 0 if not equal, 1 if otherwise.
 */

int env_call_cmp(const char *env_list, const char *input)
{
	int x;

	while (env_list[x] != '=' &&  env_list != '\0' && input[x] != '\0')
	{
		if (env_list[x] != input[x])
		{
			return (0);
		}
		x++;
	}

	if (env_list[x] == '=')
	{
		return (x + 1);
	}
	else
	{
		return (0);
	}
}

/**
 * _getenv - Function that helps get an environment variable to print
 * @name: A pointer to the name of the evironment variable
 * @_environ: A double pointer pointing to the environment variable
 * Return: value of the environment var, if it's found, NULL, if otherise.
 */

char *_getenv(const char *name, char **_environ)
{
	char *envPtr;
	int x = 0;
	int check = 0;

	while (_environ[x] != NULL)
	{
		check = env_call_cmp(_environ[x], name);

		if (check)
		{
			envPtr = _environ[x];
			break;
		}
		x++;
	}
	return (envPtr + check);
}
