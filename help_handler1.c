#include "shell.h"

/**
 * printsHelp - prints help of help built in
 *
 * Return: No Return
 */
void printsHelp(void)
{
	_puts("Shell HSH, version 1.0(1)-release (x86_64-pc-linux-gnu)\n");
	_puts("These shell commands are defined internally.\n");
	_puts("Type `help' to see this list.\n");
	_puts("Type help  'BUILTIN'' to find out more about ");
	_puts("the function 'BUILTIN'.\n\n");
	_puts(" exit [n]\n");
	_puts(" env\n");
	_puts(" setenv [VARIABLE] [VALUE]\n");
	_puts(" unsetenv [VARIABLE]\n");
	_puts(" cd [DIRECTORY]\n");
	_puts(" help [BUILTIN ...]\n");
	_puts(" alias [name[='value'] ...]\n");
}
