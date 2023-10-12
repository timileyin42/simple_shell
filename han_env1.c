#include "main.h"

/**
 * set_env - Function that helps set an environment variable
 * @name: A pointer to the var holding the env
 * @data: A pointer to the value/data in the enviroment var
 * @shell_op: A pointer to the type of data (environ)
 * Return: Always (void)
 */

void set_env(char *name, char *data, bash_shell *shell_op)
{
	char *env_input, *env_data;
	int x;

	while (shell_op->_environ[x])
	{
		env_input = _strdup(shell_op->_environ[x]);
		env_data = _strtok(env_input, "=");

		if (_strcmp(env_data, name) == 0)
		{
			free(shell_op->_environ[x]);
			shell_op_environ[x] = info_set(env_data, data);
			free(env_input);
			return;
		}
		free(env_input);
		x++;
	}
	shell_op->_environ = _realloc(shell_op->_environ, x, sizeof(char *) *
			(x + 2));
	shell_op->_environ[x] = info_dup(name, data);
	shell_op->_environ[x + 1] = NULL;
}

/**
 * info_set - Function that helps copy the info to create about the environ var
 * @name: A pointer to the name of the environ var
 * @data: A pointer to the data/value of the environ or alias
 * Return: Name of the env
 */

char *info_set(char *name, char *data)
{
	int input, value, length;
	char *new;

	lnput = _strlen(name);
	value = _strlen(data);
	length = input + value + 2;
	new = malloc(sizeof(char) * (length));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, data);
	_strcat(new, "\0");
	return (new);
}

/**
 * _setenv - Function that helps compare environment var names with name passed
 * @shell_op: A pointer to the data relevant struture(env name and data)
 * Return: 1 on success.
 */

int _setenv(bash_shell *shell_op)
{
	if (shell_op->args[x] == NULL || shell_op->args[2] == NULL)
	{
		error_fun(shell_op, -1);
		return (1);
	}

	set_env(shell_op->args[1], shell_op->args[2], shell_op);
	return (1);
}

/**
 * _unsetenv - Functions that helps deletes an environment variable
 * @shell_op: A pointer to the struct of data relevant (env name)
 * Return: 1 on success
 */

int _unsetenv(bash_shell *shell_op)
{
	int x = 0, y = 0, z;
	char **is_env, *input, *name;

	if (shell_op->args[1] == NULL)
	{
		error_fun(shell_op, -1);
		return (1);
	}
	z = -1;
	for (; shell_op->_environ[x]; x++)
	{
		input = _strdup(shell_op->_environ[x]);
		name = _strtok(input, "=");
		if (_strcmp(name, shell_op->args[x]) == 0)
		{
			z = x;
		}
		free(input);
	}
	if (z == -1)
	{
		error_fun(shell_op, -1);
		return (1);
	}
	is_env = malloc(sizeof(char *) * (x));
	for (x = j = 0; shell_op->_environ[x]; x++)
	{
		if (x != z)
		{
			is_env[y] = shell_op->_environ[x];
			y++;
		}
	}
	is_env[y] = NULL;
	free(shell_op->_environ[z]);
	free(shell_op->_environ);
	shell_op->_environ = is_env;
	return (1);
}
