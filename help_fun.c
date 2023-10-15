#include "main.h"

/**
 * help_fun - Function that helps print help messages according buitin fun
 * @shell_op: A pointer to the data struture of (args and code)
 * Return: Always (void)
 */
void help_fun(bash_shell *shell_op)
{
	get_t help_gets[] = {
		{"setenv", help_setenv_fun},
		{"env", help_env_fun},
		{"unsetenv", help_unsetenv_fun},
		{"help", help_buitin_help},
		{"exit", help_exit_fun},
		{"cd", help_cd_fun},
		{"alias", help_alias_fun},
		{NULL, NULL}
	};

	int x = 0;

	if (shell_op->args[1] == 0)
	{
		help_gen_fun();
	} else
	{
		for (; help_gets[x].name != NULL; x++)
		{
			if (_strcmp(shell_op->args[1], help_gets[x].name) == 0)
			{
				help_gets[x].func();
				break;
			}
		}
	}

	shell_op->mode = 0;
}
