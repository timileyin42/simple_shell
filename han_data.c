#include "main.h"

/**
 * memory_free - Function that helps free the memory of all the files
 * @shell_op: A pointer to the data structure
 * Return: Always (void0
 */

void memory_free(bash_shell *shell_op)
{
	unsigned int x;

	for (; shell_op->_environ[x]; x++)
	{
		free(shell_op->_environ[x]);
	}
	free(shell_op->_environ);
	free(shell_op->pid);
}

/**
 * check_data - function that helps initilize the code block
 * @shell_op: A pointer to the data structure
 * @av: argument vector
 * Return: Always (void)
 */

void check_data(bash_shell *shell_op, char **av)
{
	unsigned int x;

	shell_op->av = av;
	shell_op->code = NULL;
	shell_op->args = NULL;
	shell_op->mode = 0;
	shell_op->count = 1;

	while (environ[x] != NULL)
		x++;

	shell_op->_environ = malloc(sizeof(char *) * (x + 1));

	x = 0;
	while (environ[x] != NULL)
	{
		shell_op->_environ[x] = _strdup(environ[x]);
		x++;
	}
	shell_op->_environ[x + 1] = NULL;
	shell_op->pid = han_itoa(getpid());
}
