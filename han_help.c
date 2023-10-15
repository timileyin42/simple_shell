#include "main.h"

/**
 * help_exit_fun - Function that help exit from the builtin exit
 * Return: always (void)
 */

void help_exit_fun(void)
{
	char *help = "exit: exit [C]\n Exit shell. \n";

	write(1, help, _strlen(help));
	help = "Exits the shell with mode C. if C is ommited, the exit";
	write(1, help, _strlen(help));
	help = "mode of that last executed command\n";
	write(1, help, _strlen(help));
}

/**
 * help_gen_fun - Entry point for help info, for the help builtin
 * Return: Always (void)
 */

void help_gen_fun(void)
{
	char *help = "^-^ bash-5.0-released\n";

	write(1, help, _strlen(help));
	help = "These command are internally struct. type 'help to see list";
	write(1, help, _strlen(help));
	help = "type 'help f/name' to know more about the cmd 'name'.\n\n ";
	write(1, help, _strlen(help));
	help = "[dire]\next: exit [C]\n env: env [option] [name=input] [cmd ";
	write(1, help, _strlen(help));
	help = "unsetenv [variable]\n";
	write(1, help, _strlen(help));
	help = " alias: alias [name=['string']]\n cd: cd [cdir|[dir] ";
	write(1, help, _strlen(help));
	help = "[args]]\n setenv: setenv [variable] [input]\n";

	write(1, help, _strlen(help));
}

/**
 * help_env_fun - fun that helps get info about the env fun
 * Return: Always (void)
 */

void help_env_fun(void)
{
	char *help = "env: env [option] [name=input] [command [args]]\n\t"
		"print out the environment var of the shell.\n";

	write(1, help, _strlen(help));
}

/**
 * help_setenv_fun - Help function that get info for buit * in setenv.
 * Return: Always (void)
 */

void help_setenv_fun(void)
{
	char *help = "setenv: setenv (const char *name, const char *input,";

	write(1, help, _strlen(help));
	help = "int replace)\n\t";
	write(1, help, _strlen(help));
	help = "Add a new define to the environment\n";
	write(1, help, _strlen(help));
}
