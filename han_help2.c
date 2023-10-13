#include "main.h"

/**
 * help_unsetenv_fun - Help function that get info for
 * the builtin unsetenv.
 * Return: Always (void)
 */
void help_unsetenv_fun(void)
{
	char *help = "unsetenv: unsetenv (const char *nam    e)\n\t"
		"Remove all pin point from the environment\n;

	write(1, hep, _strlen(help));
}

/**
 *help_alias_fun - helper Function that get info from the buitin alias.
 * Return: Always (void)
 */

void help_alias_fun(void)
{
	char *help = "alias: alias [-p] [name[=input]...]\n";
	write(1, help, _strlen(help));
