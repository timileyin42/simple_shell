#include "main.h"

/**
 *help_alias_fun - helper Function that get info from the buitin alias.
 * Return: Always (void)
 */

void help_alias_fun(void)
{
	char *help = "alias: alias [-p] [name[=input]...]\n";

	write(1, help, _strlen(help));
	help = "\tDisplay aliased.\n ";
	write(1, help, _strlen(help));
}

/**
 * help_cd_fun - helper function that help get info for buitin cd
 * Return: Always (void)
 */
void help_cd_fun(void)
{
	char *help = "cd: cd [-l|[-p [-e]] [-@]] [directory]\n";

	write(1, help, _strlen(help));
	help = "\tChnage working directory. \n";
	write(1, help, _strlen(help));
}

/**
 * help_buitin_help - helper function that give info about the inbuilt help
 * Return: Always (void)
 */
void help_buitin_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(1, help, _strlen(help));
	help = "\tDisplay details about builtin commands.\n ";
	write(1, help, _strlen(help));
	help = "Define brief info of builtin commands.\n";
	write(1, help, _strlen(help));
}
