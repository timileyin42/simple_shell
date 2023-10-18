#include "main.h"

/**
 * main - Executional function of all the code block
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success.
 */

int main(__attribute__((unused)) int ac, char **av)
{
	bash_shell shell_op;

	signal(SIGINT, sign_call);
	check_data(&shell_op, av);
	shell_terminal(&shell_op);
	memory_free(&shell_op);

	if (shell_op.mode < 0)
		return (255);
	return (shell_op.mode);
}
