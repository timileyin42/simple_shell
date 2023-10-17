#include <unistd.h>
#include "shell.h"

/**
 * help_unsetenv - prints help of unsetenv built in
 *
 * Return: No Return
 */
void help_unsetenv(void)
{
	_puts("unsetenv: unsetenv [VARIABLE]\n");
	_puts("    Initializes a new environment variable, or ");
	_puts("    modifies an existing one.\n\n");
	_puts("    VARIABLE must not have the character '='.\n");
	_puts("    If no arguments are given, setenv prints the current ");
	_puts("    environment.\n");
}

/**
 * help_cd - prints help of cd built in
 *
 * Return: No Return
 */
void help_cd(void)
{
	_puts("cd: cd [DIRECTORY]\n");
	_puts("    Change the shell working directory.\n\n");
	_puts("    Change the current directory to DIR.  ");
	_puts("    The default DIR is the value of the\n");
	_puts("    HOME shell variable.\n\n");
	_puts("    Options:\n");
	_puts("    -  If a minus signed is used instead a directory, ");
	_puts("    cd will change to the\n");
	_puts("       previous used directory\n\n");
	_puts("    Each time cd runs successfuly, the env variable ");
	_puts("    PWD is updated\n\n");
	_puts("    Exit Status:\n");
	_puts("    Returns 1 if the directory is changed, and if $PWD is set ");
	_puts("    successfully when\n");
	_puts("    is used; -1 otherwise.\n");
}
/**
 * help_help - prints help of help built in
 *
 * Return: No Return
 */
void help_help(void)
{
	_puts("help: help [BUILTIN ...]\n");
	_puts("    Display information about builtin commands.\n\n");
	_puts("    Displays brief summaries of builtin commands.  If BUILTIN is\n");
	_puts("    specified, gives detailed help on all commands ");
	_puts("    matching BUILTIN,\n");
	_puts("    otherwise the list of help topics is printed.\n\n");
	_puts("    Arguments:\n");
	_puts("      BUILTIN   Builtin specifying a help topic\n\n");
	_puts("    Exit Status:\n");
	_puts("    Returns success unless PATTERN is not found or an invalid ");
	_puts("    option is given.\n");
}
/**
 * help_alias - prints help of alias built in
 *
 * Return: No Return
 */
void help_alias(void)
{
	_puts("alias: alias alias [name[='value'] ...]\n");
	_puts("    Define or display aliases.\n\n");
	_puts("    Without arguments, `alias' prints the list of aliases ");
	_puts("    in the reusable\n");
	_puts("    form `alias NAME=VALUE' on standard output.\n\n");
	_puts("     Otherwise, an alias is defined for each NAME whose ");
	_puts("    VALUE is given.\n");
	_puts("    A trailing space in VALUE causes the next word to ");
	_puts("    be checked for\n");
	_puts("    alias substitution when the alias is expanded.\n\n");
	_puts("    Exit Status:\n");
	_puts("    alias returns true unless a NAME is supplied for which ");
	_puts("    no alias has been\n");
	_puts("    defined.\n");
}
