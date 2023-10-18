#include "main.h"

/**
 * error_fun - Functions that call the error and its encompasess
 * @shell_op: A pointer to the data structure that contain the args
 * @error_output: error value in the shell terminal
 * Return: error
 */

int error_fun(bash_shell *shell_op, int error_output)
{
	info_t error_infos[] = {
		{-1, env_error_fun},
		{126, error_path_fail},
		{2, exit_error},
		{127, no_error_detect},
		{2, command_error},
		{0, NULL}
	};

	int x;

	for (; error_infos[x].error_msg != NULL; x++)
	{
		if (error_output == error_infos[x].error_value)
		{
			char *error = error_infos[x].error_msg(shell_op);

			if (error)
			{
				write(2, error, _strlen(error));
			}
			break;
		}
	}
	shell_op->mode = error_output;
	return (error_output);
}
