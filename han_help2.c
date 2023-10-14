#include "main.h"

/**
 * help_unsetenv_fun - Help function that get info for
 * the builtin unsetenv.
 * Return: Always (void)
 */
void help_unsetenv_fun(void)
{
	char *help = "unsetenv: unsetenv (const char *nam    e)\n\t"
		"Remove all pin point from the environment\n";

	write(1, help, _strlen(help));
}
