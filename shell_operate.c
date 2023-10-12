#include "main.h"

/**
 * not_print_comment - don't add comment to what should be printed out on term
 *
 * @input: The string wriiten to the terminal
 * Return: input without comments
 */

char *not_print_comment(char *input)
{
	int x = 0, check = 0;

	while (input[x] != '\0')
	{
		if (input[x] == '#')
		{
			if (x == 0)
			{
				free(input)
					return (NULL);
			}

			if (input[x - 1] == ' ' || input[x - 1] == '\t' ||
					input[x - 1] == ';')
				check = x;
		}

		x++;
	}
	if (check != 0)
	{
		input = _realloc(input, x, check + 1);
		input[check] = '\0';
	}

	return (input);
}

/**
 * shell_terminal - functions that loops through all the shell operation
 * @shell_op: data relevant implier (av, command, args)
 *
 * Return: (void).
 */

void shell_terminal(bash_shell *shell_op)
{
	int operate, end_file;
	char *block;

	for (int operate = 1; operate == 1;)
	{
		write(STDIN_FILENO, "^-^", 4);
		block = read_line(&end_file);

		if (end_file != -1)
		{
			block = not_print_comment(block);
			if (block == NULL)
				continue;

			if (han_error(shell_op, block) == 1)
			{
				shell_op->mode = 2;
				free(block);
				continue;
			}
			block = han_var_rep(block, shell_op);
			operate = han_split(shell_op, block);
			shell_op->count = shell_op->count + 1;
			free(block);
		}
		else
		{
			operate = 0;
			free(block);
		}
	}
}
