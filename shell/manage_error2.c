#include "main.h"

/**
 * env_error_fun - Functions that helps check for error message in get_env
 * @shell_op:  A pointer to the type of data structure (count, arguments)
 * Return: error messages
 */

char *env_error_fun(bash_shell *shell_op)
{
	char *error, *check, *msg;
	int len;

	check = han_itoa(shell_op->count);
	msg = ": can't add/remove from environment\n";
	len = _strlen(shell_op->av[0]) + _strlen(check);
	len = len + _strlen(shell_op->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(error);
		free(check);
		return (NULL);
	}
	_strcpy(error, shell_op->av[0]);
	_strcat(error, ": ");
	_strcat(error, check);
	_strcat(error, ": ");
	_strcat(error, shell_op->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(check);

	return (error);
}

/**
 * error_path_fail - Function that helps print error for path access denied
 * @shell_op: A pointer to the type of data structure (count, arguments).
 * Return: The error message
 */

char *error_path_fail(bash_shell *shell_op)
{
	char *error, *check;
	int len;

	check = han_itoa(shell_op->count);
	len = _strlen(shell_op->av[0]) + _strlen(check);
	len = len + _strlen(shell_op->args[0]) + 24;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(error);
		free(check);
		return (NULL);
	}
	_strcpy(error, shell_op->av[0]);
	_strcat(error, ": ");
	_strcat(error, check);
	_strcat(error, ": ");
	_strcat(error, shell_op->args[0]);
	_strcat(error, ": permission denied\n");
	_strcat(error, "\0");
	free(check);
	return (error);
}
