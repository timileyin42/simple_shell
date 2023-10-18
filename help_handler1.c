#include "main.h"

/**
 * printsHelp - prints help of help built in
 *
 * Return: No Return
 */
void printsHelp(void)
{
	write_buf("Shell HSH, version 1.0(1)-release (x86_64-pc-linux-gnu)\n");
	write_buf("These shell commands are defined internally.\n");
	write_buf("Type `help' to see this list.\n");
	write_buf("Type help  'BUILTIN'' to find out more about ");
	write_buf("the function 'BUILTIN'.\n\n");
	write_buf(" exit [n]\n");
	write_buf(" env\n");
	write_buf(" setenv [VARIABLE] [VALUE]\n");
	write_buf(" unsetenv [VARIABLE]\n");
	write_buf(" cd [DIRECTORY]\n");
	write_buf(" help [BUILTIN ...]\n");
	write_buf(" alias [name[='value'] ...]\n");
}
