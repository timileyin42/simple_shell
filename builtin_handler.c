#include "main.h"

/**
 * _exit_cmd - built in command exit
 * @bash_s: struct containing shell info
 *
 * Return: -1 if error
 */
ssize_t _exit_cmd(bash *bash_s)
{
	long valueToExit;

	if (bash_s->options[1] == NULL || _isnumber(bash_s->options[1]))
	{
		valueToExit = _atoi(bash_s->options[1]);

		if (valueToExit >= 0 && valueToExit < INT_MAX)
		{
			if (valueToExit > 255)
				valueToExit %= 256;
			if (bash_s->options[1] == NULL)
				valueToExit = bash_s->exitnum[0];
			free(*(bash_s->options));
			free(bash_s->options);
			if (*(bash_s->envCpy))
				free_doubpoint(*(bash_s->envCpy));
			free(bash_s);
			exit(valueToExit);
		}
	}

	_error(STDERR_FILENO, bash_s, 2);
	free(bash_s->options);
	return (-1);
}
/**
 * _env_cmd - built in command env
 * @bash_s: struct containing shell info
 *
 * Return: 1 if succesful
 */
ssize_t _env_cmd(bash *bash_s)
{
	char **str;
	int check = 1;

	if (*(bash_s->envCpy) == NULL)
	{
		write(2, "Environment is Null, Can't Print it\n", 36);
		bash_s->exitnum[0] = 2;
		free(bash_s->options);
		return (-1);
	}

	str = *(bash_s->envCpy);

	if (bash_s->options[1] == NULL)
	{
		for (; str && *str; str++)
		{
			write(STDOUT_FILENO, *str, _strlen(*str));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	else
	{
		_error(STDIN_FILENO, bash_s, 2);
		check = -1;
	}

	free(bash_s->options);
	return (check);
}
/**
 * _setenv_cmd - built in command setenv
 * @bash_s: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t _setenv_cmd(bash *bash_s)
{
	char **newenv;
	char *variable = NULL;
	char *value = NULL;

	if (bash_s->options[1])
	{
		variable = bash_s->options[1];
		if (!bash_s->options[2])
		{
			write(STDERR_FILENO, "Invalid VALUE\n", 14);
			bash_s->exitnum[0] = 2;
			free(bash_s->options);
			return (-1);
		}
		else
			value = bash_s->options[2];

	}
	if (variable == 0)
	{
		write(STDERR_FILENO, "Invalid VARIABLE\n", 17);
		bash_s->exitnum[0] = 2;
		free(bash_s->options);
		return (-1);
	}

	newenv = _setenv(*(bash_s->envCpy), variable, value, bash_s);

	if (newenv == 0)
	{
		free(bash_s->options);
		return (-1);
	}

	*(bash_s->envCpy) = newenv;
	free(bash_s->options);
	return (1);
}
/**
 * _unsetenv_cmd - built in command unsetenv
 * @bash_s: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t _unsetenv_cmd(bash *bash_s)
{
	char **newenv;
	char *variable = NULL;

	if (bash_s->options[1])
		variable = bash_s->options[1];
	else
	{
		bash_s->exitnum[0] = 2;
		write(STDERR_FILENO, "Please provide an argument\n", 27);
		return (free(bash_s->options), -1);
	}

	if (variable == 0)
	{
		free(bash_s->options);
		return (1);
	}

	newenv = _unsetenv(*(bash_s->envCpy), variable, bash_s);

	if (newenv == 0 && bash_s->unsetnull[0] == 0)
	{
		free(bash_s->options);
		bash_s->exitnum[0] = 2;
		return (-1);
	}

	*(bash_s->envCpy) = newenv;
	free(bash_s->options);
	return (1);
}

/**
 * built_ints - checks if cmd is a built in
 * @bash_s: struct containing shell info
 *
 * Return: On fail 0
 */
ssize_t built_ints(bash *bash_s)
{
	b_ins ops[] = {
		{"exit", _exit_cmd},
		{"env", _env_cmd},
		{"setenv", _setenv_cmd},
		{"unsetenv", _unsetenv_cmd},
		{"cd", _cd_cmd},
		{"help", _help_cmd}
	};

	int x, builtcheck; /* lenght of ops array */

	for (x = 0; x < 6; x++)
	{
		if (!_strcmp(bash_s->cmd, ops[x].cmd))
		{
			bash_s->errnum[0] = bash_s->errnum[0] + 1;
			builtcheck = ops[x].f(bash_s);
			if (builtcheck == 1)
				bash_s->exitnum[0] = 0;
			return (builtcheck);
		}
	}

	return (0);
}