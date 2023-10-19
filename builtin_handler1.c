#include "main.h"

/**
 * cd_home - auxiliary function of cd built in
 * @bash_s: struct containing shell info
 * @currdir: current directory
 *
 * Return: pointer to HOME or NULL if fail
 */
char *cd_home(bash *bash_s, char __attribute__((unused)) *currdir)
{
	char *home, *direct = NULL;

	home = _getenv("HOME", *(bash_s->envCpy));
	if (home)
		direct = home + 5;

	return (direct);
}

/**
 * han_cd - auxiliary function of cd built in
 * @bash_s: struct containing shell info
 * @currdir: the current directory
 *
 * Return: Pointer to dir or NULL if fail
 */
char *han_cd(bash *bash_s, char *currdir)
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
	if (oldpwd2 == NULL)
	{
		oldpwd = _strdup(currdir);
		/* free(oldpwd), free(bash_s->options), free(currdir); */
		/* return (bash_s->exitnum[0] = 2, NULL); */
	}

	direct = oldpwd;

	return (direct);
}

/**
 * cd_cmd - built in command cd
 * @bash_s: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t cd_cmd(bash *bash_s)
{
	char *currdirect = NULL, *direct = NULL, **new_env, *oldpwd = NULL;
	int exit = 1, check = 1, checkminus = 0;

	currdirect = getcwd(NULL, 4096);
	if (currdirect == NULL)
		return (error_fun(4, bash_s, 2), free(bash_s->options), -1);
	if (!bash_s->options[1] ||
			(bash_s->options[1] && (!_strcmp(bash_s->options[1], "~"))))
	{
		direct = cd_home(bash_s, currdirect);
		if (direct == NULL)
			return (free(bash_s->options), free(currdirect), 1);
	}
	else
		if (!_strcmp(bash_s->options[1], "-"))
		{
			direct = han_cd(bash_s, currdirect);
			if (direct == NULL)
				return (free(bash_s->options), free(currdirect), 1);
			checkminus = 1;
		}
		else
			direct = bash_s->options[1];
	if (direct)
		check = chdir(direct);
	if (check == 0 && checkminus == 1)
		write(STDOUT_FILENO, direct, _strlen(direct)), write(STDOUT_FILENO, "\n", 1);
	if (check != 0)
		error_fun(4, bash_s, 2), exit = -1;
	else
	{
		new_env = _setenv(*(bash_s->envCpy), "PWD", direct, bash_s);
		*(bash_s->envCpy) = new_env;
		new_env = _setenv(*(bash_s->envCpy), "OLDPWD", currdirect, bash_s);
		*(bash_s->envCpy) = new_env;
	}
	free(bash_s->options), free(currdirect), free(oldpwd);
	if (checkminus == 1)
		free(direct);
	return (exit);
}
