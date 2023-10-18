#include "main.h"

/**
 * auxcd2 - auxiliary function of cd built in
 * @bash_s: struct containing shell info
 * @currdir: current directory
 *
 * Return: pointer to HOME or NULL if fail
 */
char *auxcd2(bash *bash_s, char __attribute__((unused)) *currdir)
{
	char *home, *direct = NULL;

	home = _getenv("HOME", *(bash_s->envCpy));
	if (home)
		direct = home + 5;

	return (direct);
}

/**
 * auxcd - auxiliary function of cd built in
 * @bash_s: struct containing shell info
 * @currdir: the current directory
 *
 * Return: Pointer to dir or NULL if fail
 */
char *auxcd(bash *bash_s, char *currdir)
{
	char *oldpwd2 = NULL, *oldpwd = NULL, *direct = NULL;

	if (bash_s->options[1] && bash_s->options[2])
	{
		write(STDERR_FILENO, "cd: too many arguments\n", 23);
		bash_s->exitnum[0] = 2;
		free(bash_s->options);
		free(currdir);
		return (direct);
	}

	oldpwd2 = _strdup(_getenv("OLDPWD", *(bash_s->envCpy)));
	if (oldpwd2)
		oldpwd = _strdup(oldpwd2 + 7), free(oldpwd2);
	if (!oldpwd2)
	{
		oldpwd = _strdup(currdir);
		/* free(oldpwd), free(bash_s->options), free(currdir); */
		/* return (bash_s->exitnum[0] = 2, NULL); */
	}

	direct = oldpwd;

	return (direct);
}

/**
 * _cd_cmd - built in command cd
 * @bash_s: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t _cd_cmd(bash *bash_s)
{
	char *currdir = NULL, *dir = NULL, **newenv, *oldpwd = NULL;
	int exit = 1, check = 1, checkminus = 0;

	currdir = getcwd(NULL, 4096);
	if (currdir == NULL)
		return (_error(4, bash_s, 2), free(bash_s->options), -1);
	if (!bash_s->options[1] ||
			(bash_s->options[1] && (!_strcmp(bash_s->options[1], "~"))))
	{
		dir = auxcd2(bash_s, currdir);
		if (dir == NULL)
			return (free(bash_s->options), free(currdir), 1);
	}
	else
		if (!_strcmp(bash_s->options[1], "-"))
		{
			dir = auxcd(bash_s, currdir);
			if (!dir)
				return (free(bash_s->options), free(currdir), 1);
			checkminus = 1;
		}
		else
			dir = bash_s->options[1];
	if (dir)
		check = chdir(dir);
	if (check == 0 && checkminus == 1)
		write(STDOUT_FILENO, dir, _strlen(dir)), write(1, "\n", 1);
	if (check != 0)
		_error(4, bash_s, 2), exit = -1;
	else
	{
		newenv = _setenv(*(bash_s->envCpy), "PWD", dir, bash_s);
		*(bash_s->envCpy) = newenv;
		newenv = _setenv(*(bash_s->envCpy), "OLDPWD", currdir, bash_s);
		*(bash_s->envCpy) = newenv;
	}
	free(bash_s->options), free(currdir), free(oldpwd);
	if (checkminus == 1)
		free(dir);
	return (exit);
}
