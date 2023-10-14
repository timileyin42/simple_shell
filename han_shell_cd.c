#include "main.h"

/**
 * shell_change - Functions that helps change the current directory in shell
 * @shell_op: A pointer to the data structure
 * Return: 1 on succes
 */

int shell_change(bash_shell *shell_op)
{
	int cd_home, p_wd, cd_check;
	char direct;

	direct = shell_op->args[1];

	if (direct != NULL)
	{
		cd_home = _strcmp("$HOME", direct);
		p_wd = _strcmp("~", direct);
		cd_check = _strcmp("--", direct);
	}
	if (direct == NULL || !cd_home || !p_wd || !cd_check)
	{
		cd_home(shell_op);
		return (1);
	}
	if (_strcmp("-", direct) == 0)
	{
		cd_prev_dir(shell_op);
		return (1);
	}

	if (_strcmp(".", direct) == 0 || _strcmp("..", direct) == 0)
	{
		cd_parent(shell_op);
		return (1);
	}
	cd_input(shell_op);
	return (1);
}
