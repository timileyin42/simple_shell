#include "main.h"

/**
 * shell_exit - Functions that helps exit the shell
 * @shell_op: A pointer to the type of data struture
 * Return: 0, if success.
 */

int shell_exit(bash_shell *shell_op)
{
	unsigned int stop;
	int str, digit, large_num;

	if (shell_op->args[1] != NULL)
	{
		stop = _atoi(shell_op->args[1]);
		digit = _isdigit(shell_op->args[1]);
		str = _strlen(shell_op->args[1]);
		large_num = stop > (unsigned int)INT_MAX;
		if (!digit || str > 10 || large_num)
		{
			error_fun(shell_op, 2);
			shell_op->mode = 2;
			return (1);
		}
		shell_op->mode = (stop % 256);
	}
	return (0);
}
