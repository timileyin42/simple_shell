#include "main.h"

/**
 * help_unsetenv - prints help of unsetenv built in
 *
 * Return: No Return
 */
void help_unsetenv(void)
{
	write_buf("unsetenv: unsetenv [VARIABLE]\n");
	write_buf("    Initializes a new environment variable, or ");
	write_buf("    modifies an existing one.\n\n");
	write_buf("    VARIABLE must not have the character '='.\n");
	write_buf("    If no arguments are given, setenv prints the current ");
	write_buf("    environment.\n");
}

/**
 * help_cd - prints help of cd built in
 *
 * Return: No Return
 */
void help_cd(void)
{
	write_buf("cd: cd [DIRECTORY]\n");
	write_buf("    Change the shell working directory.\n\n");
	write_buf("    Change the current directory to DIR.  ");
	write_buf("    The default DIR is the value of the\n");
	write_buf("    HOME shell variable.\n\n");
	write_buf("    Options:\n");
	write_buf("    -  If a minus signed is used instead a directory, ");
	write_buf("    cd will change to the\n");
	write_buf("       previous used directory\n\n");
	write_buf("    Each time cd runs successfuly, the env variable ");
	write_buf("    PWD is updated\n\n");
	write_buf("    Exit Status:\n");
	write_buf("    Returns 1 if the dir is changed, and if $PWD is set ");
	write_buf("    successfully when\n");
	write_buf("    is used; -1 otherwise.\n");
}
/**
 * help_help - prints help of help built in
 *
 * Return: No Return
 */
void help_help(void)
{
	write_buf("help: help [BUILTIN ...]\n");
	write_buf("    Display information about builtin commands.\n\n");
	write_buf("    Disp brief summ of builtin commands.  If BUILTIN is\n");
	write_buf("    specified, gives detailed help on all commands ");
	write_buf("    matching BUILTIN,\n");
	write_buf("    otherwise the list of help topics is printed.\n\n");
	write_buf("    Arguments:\n");
	write_buf("      BUILTIN   Builtin specifying a help topic\n\n");
	write_buf("    Exit Status:\n");
	write_buf("    Returns success unless PATTERN is not found or an invalid ");
	write_buf("    option is given.\n");
}
/**
 * help_alias - prints help of alias built in
 *
 * Return: No Return
 */
void help_alias(void)
{
	write_buf("alias: alias alias [name[='value'] ...]\n");
	write_buf("    Define or display aliases.\n\n");
	write_buf("    Without arguments, `alias' prints the list of aliases ");
	write_buf("    in the reusable\n");
	write_buf("    form `alias NAME=VALUE' on standard output.\n\n");
	write_buf("     Otherwise, an alias is defined for each NAME whose ");
	write_buf("    VALUE is given.\n");
	write_buf("    A trailing space in VALUE causes the next word to ");
	write_buf("    be checked for\n");
	write_buf("    alias substitution when the alias is expanded.\n\n");
	write_buf("    Exit Status:\n");
	write_buf("    alias returns true unless a NAME is supplied for which ");
	write_buf("    no alias has been\n");
	write_buf("    defined.\n");
}
