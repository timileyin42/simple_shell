#include "main.h"

/**
 * syntax - function that helps check for the function to print error message
 * @shell_op: A pointer to the data structure
 * @command:  A pointer to the input string
 * Return: 98 if there is an error. 0 if otherwise
 */

int syntax(bash_shell *shell_op, char *command)
{
	int check, input, x;

	check = 0;
	input =  set_char(command, &check);
	if (input == -1)
	{
		han_error_print(shell_op, command, check, 0);
		return (1);
	}

	x = error_finder(command + check, 0, *(command + check));
	if (x != 0)
	{
		han_error_print(shell_op, command, check + x, 1);
		return (98);
	}
	return (0);
}
