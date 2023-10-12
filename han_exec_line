#include "main.h"

/**
 * han_exec_line - Functions that finds the builtins and commands
 * @shell_op: A pointer to the data struture.
 * Return: 1 on success.
 */

int han_exec_line(bash_shell *shell_op)
{
	int (*builtin)(bash_shell);

	if (shell_op->args[0] == NULL)
		return (1);

	builtin = han_builtin(shell_op->args[0]);
	if (builtin != NULL)
		return (builtin(shell_op));
	return (shell_exec(shell_op));
}
