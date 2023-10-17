#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _puts - prints string to std output
 * @s: string (must be NULL terminated)
 *
 * Return: No Return
 */
void _puts(char *s)
{
	write(1, s, _strlen(s));
}
/**
 * help_exit - prints help of exit built in
 *
 * Return: No Return
 */
void help_exit(void)
{
	_puts("exit: exit [n]\n");
	_puts("    Exit the shell.\n\n");
	_puts("    Exits the shell with a status of N.  ");
	_puts("    If N is omitted, the exit status\n");
	_puts("    is that of the last command executed.\n");
}
/**
 * help_env - prints help of env built in
 *
 * Return: No Return
 */
void help_env(void)
{
	_puts("env: env\n");
	_puts("    prints the current environment.\n\n");
	_puts("    Has no options\n");
}
/**
 * help_setenv - prints help of setenv built in
 *
 * Return: No Return
 */
void help_setenv(void)
{
	_puts("setenv: setenv [VARIABLE] [VALUE]\n");
	_puts("    Initializes a new environment variable, ");
	_puts("    or modifies an existing one.\n\n");
	_puts("    VARIABLE must not have the character '='.\n");
	_puts("    If no arguments are given, setenv prints ");
	_puts("    the current environment.\n");
}


/**
 * _help_cmd - help of built in commands
 * @shpack: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t _help_cmd(hshpack *shpack)
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

	int i = 7;
	int p = 1;

	for (; shpack->options[p]; p++, i = 7)
	{
		while (i--)
			if (!_strcmp(shpack->options[p], help[i].built))
				help[i].h(), bcheck = 1;
	}
	if (shpack->options[1] == NULL)
	{
		printsHelp();
		bcheck = 1;
	}
	if (bcheck == 0)
	{
		check = -1;
		_error(6, shpack, 2);
	}

	free(shpack->options);
	return (check);
}
