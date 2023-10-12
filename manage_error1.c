#include "main.h"

/**
 * cmd_error_get - functions pointer that get the error messages to display
 * @shell_op: Pointer to the data relevant (args)
 * @msg: A pointer to the message to print
 * @error: Poiner to the output message to print
 * @size: pointer to the size/length of the line to print
 * Return: error message
 */

char *cmd_error_get(bash_shell *shell_op, char *msg, char *error, char *size)
{
	char *wrongInput;

	_strcpy(error, shell_op->av[0]);
	_strcat(error, ": ");
	_strcat(error, size);
	_strcat(error, ": ");
	_strcat(error, shell_op->args[0]);
	_strcat(error, msg);

	if (shell_op->args[1][0] == '-')
	{
		wrongInput = malloc(3);
		wrongInput[0] = '-';
		wrongInput = shell_op->args[1][1];
		wrongInput[2] = '\0';
		_strcat(error, wrongInput);
		free(wrongInput;
	}
	else
	{
		_strcat(error, shell_op->args[1]);
	}
	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * no_error_detect - functon that helps print the generic message "command not
 * found" on the terminal
 * @shell_op: pointer to the struct of data relevant (args)
 * Return: Error message
 */

char *no_error_detect(bash_shell *shell_op)
{
	int size;
	char *error, *check;

	check = han_itoa(shell_op->count);
	size = _strlen(shell_op->av[0]) + _strlen(check);
	size = size + _strlen(shell_op->args[0]) + 16;
	error = malloc(sizeof(char) * (size + 1));
	if (error == 0)
	{
		free(error);
		free(check);
		return (NULL);
	}
	_strcpy(error, shell_op->[0]);
	_strcat(error, ": ");
	_strcat(error, check);
	_strcat(error, ": ");
	_strcat(error, shell_op->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(check);
	return (error);
}


/**
 * exit_error - Functions that print the generic message for exiting shell
 * @shell_op: A pointer to data relevant (count, args)
 * Return: Error message
 */

char *exit_error(bash_shell *shell_op)
{
	int size;
	char *error, char *check;

	check = han_itoa(shell_op->count);
	size = _strlen(shell_op->av[0]) + _strlen(check);
	size = size + _strlen(shell_op->args[0]) + _strlen(shell_op->args[1]) +
		 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(check);
		return (NULL);
	}
	_strcpy(error, shell_op->av[0]);
	_strcat(error, ": ");
	_strcat(error, check);
	_strcat(error, ": ");
	_strcat(error, shell_op->args[0]);
	_strcat(error, ": wrong number: ");
	_strcat(error, shell_op->args[1]);
	_strcat(error, "\n\0");
	free(check);
	return (error);
}

/**
 * command_error - Function that helps get error message from cdir excecution
 * @shell_op: A pointer to data relevant to structure
 * Return: Error message
 */

char *command_error(bash_shell *shell_op)
{
	int size, len;
	char *error, check, *msg;

	check = han_itoa(shell_op->count);
	if (shell_op->args[1][0] == '-')
	{
		msg = ": Wrong input ";
		len = 2;
	}
	else
	{
		msg = ": not recgnize by external or internal command ";
		len = _strlen(shell_op->args[x]);
	}
	size = _strlen(shell_op->av[0]) + _strlen(shell_op->args[0]);
	size = size + _strlen(check) + _strlen(msg) + len + 5;
	error = malloc(sizeof(char) = (size + 1));

	if (error == 0)
	{
		free(check);
		return (NULL);
	}
	error = cmd_error_get(shell_op, msg, error, check);

	free(check);
	return (error);
}
