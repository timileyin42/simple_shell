#include "main.h"

/**
 * cd_parent - functions that help change to parent directory
 * @shell_op: A pointer to the data structure of (environ)
 * Return: Always (void)
 */

void cd_parent(bash_shell *shell_op)
{
	char pwd[PATH_MAX];
	char *direct, *cd_wd, *cd_tokenize;
	int x = 0;

	getcwd(pwd, sizeof(pwd));
	cd_wd = _strdup(pwd);
	set_env("OLDPWD", cd_wd, shell_op);
	direct = shell_op->args[1];
	if (_strcmp(".", direct) == 0 || _strcmp("/", cd_wd) == 0)
	{
		if (_strcmp(".", direct) == 0)
			set_env("PWD", cd_wd, shell_op);
		free(cd_wd);
		return;
	}
	cd_tokenize = cd_wd;
	rev_string(cd_tokenize);
	cd_tokenize = _strtok(cd_tokenize, "/");
	cd_tokenize = (cd_tokenize != NULL) ? _strtok(NULL, "\0") : NULL;
	if (cd_tokenize != NULL)
		rev_string(cd_tokenize);
	if (cd_tokenize != NULL)
	{
		directory_check(cd_tokenize, &x);
		set_env("PWD", cd_tokenize, shell_op);
	}
	else
	{
		directory_check("/", &x);
		set_env("pwd", "/", shell_op);
	}
	shell_op->mode = 0;
	free(cd_wd);
}

/**
 * cd_input - Function that helps change to the directory input by the user
 * @shell_op: A pointer to the data structure(directories)
 * Return: Always (void)
 */

void cd_input(bash_shell *shell_op)
{
	char *direct, *cd_wd, *cd_direct;
	char pwd[PATH_MAX];
	int x = 0;

	getcwd(pwd, sizeof(pwd));

	direct = shell_op->args[1];
	if (directory_check(direct, &x) == -1)
	{
		error_fun(shell_op, 2);
		return;
	}

	cd_wd = _strdup(pwd);
	set_env("OLDPWD", cd_wd, shell_op);
	cd_direct = _strdup(direct);
	set_env("PWD", cd_direct, shell_op);

	free(cd_wd);
	free(cd_direct);
	shell_op->mode = 0;

	directory_check(direct, &x);
}

/**
 * cd_home - Functins that helps changes to home directory
 * @shell_op: A pointer to the data structure (environ)
 * Return: Always (void)
 */

void cd_home(bash_shell *shell_op)
{
	char pwd[PATH_MAX];
	char *cd_home, *home;
	int x = 0;

	getcwd(pwd, sizeof(pwd));
	cd_home = _strdup(pwd);

	home = _getenv("HOME", shell_op->_environ);

	if (!home)
	{
		set_env("OLDPWD", cd_home, shell_op);
		free(cd_home);
		return;
	}
	if (directory_check(home, &x) == -1)
	{
		error_fun(shell_op, 2);
		free(cd_home);
		return;
	}
	set_env("OLDPWD", cd_home, shell_op);
	set_env("PWD", home, shell_op);
	free(cd_home);
	shell_op->mode = 0;
}

/**
 * cd_prev_dir - Function that helps change to previus directory
 * @shell_op: A pointer tot the type of data structure
 * Return: Always (void)
 */

void cd_prev_dir(bash_shell *shell_op)
{
	char *cd_wd, *old_dir, *cd_dir, *cd_prev_dir;
	char pwd[PATH_MAX];
	int x = 0;

	getcwd(pwd, sizeof(pwd));
	cd_dir = _strdup(pwd);

	old_dir = _getenv("OLDPWD", shell_op->_environ);

	if (!old_dir)
		cd_prev_dir = cd_dir;
	else
		cd_prev_dir = _strdup(old_dir);
	set_env("OLDPWD", cd_dir, shell_op);
	if (directory_check(cd_prev_dir, &x) == -1)
		set_env("PWD", cd_dir, shell_op);
	else
		set_env("PWD", cd_prev_dir, shell_op);
	cd_wd = _getenv("PWD", shell_op->_environ);
	write(2, cd_wd, _strlen(cd_wd));
	write(2, "\n", 1);
	free(cd_dir);
	if (old_dir)
		free(cd_prev_dir);
	shell_op->mode = 0;
	directory_check(cd_wd, &x);
}
