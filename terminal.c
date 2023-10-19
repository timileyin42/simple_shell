#include "main.h"

/**
 * shell_cmd - Function that checks for input in after shell prompt
 * @ac: count of main arguments
 * @av: main arguments
 * @bufsize: size of buffer in prompt
 * @buffer: buffer in prompt
 * @bash_s: struct of shell info
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char **shell_cmd(int ac, char **av, size_t *bufsize,
		   char **buffer, bash *bash_s)
{
	ssize_t ch;
	char **command;
	int exitnum;

	if (ac == 1)
	{
		if (isatty(0))
			write(STDOUT_FILENO, "BASH$ ", 5);
		ch = getline(buffer, bufsize, stdin);

		if (ch == -1)
		{
			exitnum = bash_s->exitnum[0];
			free(*buffer);
			if (*(bash_s->envCpy))
				free_pointer(*(bash_s->envCpy));
			free(bash_s);
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);
			exit(exitnum);
		}
		if (**buffer == '#' || !ch || **buffer == '\n')
			return (NULL);
		*buffer = deleteComment(*buffer);
		command = parameter_fun(*buffer, bash_s);
	}
	else
	{
		command = malloc(sizeof(char *) * (ac - 1));
		if (command == NULL)
		{
			error_fun(7, bash_s, 1);
			return (NULL);
		}

		command[ac - 1] = '\0';
		while (ac--)
			command[ac - 1] = av[ac];
	}
	return (command);
}

/**
 * deleteComment - function that helps delete comment inside a command line
 *
 * @str: string to operate
 *
 * Return: pointer to string
 *
 */
char *deleteComment(char *str)
{
	char *org = str;

	for (; str && *str; str++)
		if (*str == '#' && *(str - 1) == ' ')
		{
			*str = '\0';
			break;
		}

	return (org);
}
