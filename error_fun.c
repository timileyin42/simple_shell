#include "main.h"

/**
 * error_fun - Functions that call the error and its encompasess
 * @shell_op: A pointer to the data structure that contain the args
 * @error_output: error value in the shell terminal
 * Return: error
 */

int error_fun(bash_shell *shell_op, int error_output)
{
	char *error;

	switch (error_output)
	{
		case -1:
			error = error_env(shell_op);
			break;
		case 126:
			error = error_path_126(shell_op);
			break;
		case 127:
			error = error_not_found(shell_op);
			break;
		case 2:
			if (_strcmp("exit",shell_op->args[0]) == 0)
				error = error_exit_shell(shell_op);
			else if (_strcmp("cd", shell_op->args[0]) == 0)
				error = error_get_cd(shell_op);
			break;
		}
	if (error)
	{
		write(2, error, _strlen(error));
		free(error);
	}
	shell_op->mode = error_output;
	return (error_output);
}
