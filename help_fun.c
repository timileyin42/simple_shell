#include "main.h"

/**
 * write_buf - prints string to std output
 * @s: string (must be NULL terminated)
 *
 * Return: No Return
 */
void write_buf(char *s)
{
	write(STDOUT_FILENO, s, _strlen(s));
}
/**
 * help_exit - prints help of exit built in
 *
 * Return: No Return
 */
void help_exit(void)
{
	write_buf("exit: exit [n]\n");
	write_buf("    Exit the shell.\n\n");
	write_buf("    Exits the shell with a status of N.  ");
	write_buf("    If N is omitted, the exit status\n");
	write_buf("    is that of the last command executed.\n");
}
/**
 * help_env - prints help of env built in
 *
 * Return: No Return
 */
void help_env(void)
{
	write_buf("env: env\n");
	write_buf("    prints the current environment.\n\n");
	write_buf("    Has no options\n");
}
/**
 * help_setenv - prints help of setenv built in
 *
 * Return: No Return
 */
void help_setenv(void)
{
	write_buf("setenv: setenv [VARIABLE] [VALUE]\n");
	write_buf("    Initializes a new environment variable, ");
	write_buf("    or modifies an existing one.\n\n");
	write_buf("    VARIABLE must not have the character '='.\n");
	write_buf("    If no arguments are given, setenv prints ");
	write_buf("    the current environment.\n");
}


/**
 * help_cmd - help of built in commands
 * @bash_s: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t help_cmd(bash *bash_s)
{
	int check = 1, bcheck = 0;
	helps help[] = {
		{"exit", help_exit},
		{"env", help_env},
		{"setenv", help_setenv},
		{"unsetenv", help_unsetenv},
		{"cd", help_cd},
		{"help", help_help},
		{"alias", help_alias}
	};

	int x = 7;
	int p = 1;

	for (; bash_s->options[p]; p++, x = 7)
	{
		while (x--)
			if (!_strcmp(bash_s->options[p], help[x].built))
				help[x].h(), bcheck = 1;
	}
	if (bash_s->options[1] == NULL)
	{
		printsHelp();
		bcheck = 1;
	}
	if (bcheck == 0)
	{
		check = -1;
		error_fun(6, bash_s, 2);
	}

	free(bash_s->options);
	return (check);
}
