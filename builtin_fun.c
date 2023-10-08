#include "main.h"

/**
 * builtin_fun - function that pass the needed command to arg
 * @command: The command pass
 * Return: Function pointer to the builtin command
 */

int (*builtin_fun(char *command))(bash_shell *)
{
	get_builtin builtin[] = {
		{"env", _env },
		{"exit", shell_exit }
		{"cd", shell_cd }
		{ NULL, NULL }
	};

	int x = 0;

	while (builtin[x].name != NULL)
	{
		if (_strcmp(builtin[x].name, command) == 0)
			return (builtin[x].s);
		x++;
	}

	return (NULL); /* if the command is not found */
}
