#include <limits.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _exit_cmd - built in command exit
 * @shpack: struct containing shell info
 *
 * Return: -1 if error
 */
ssize_t _exit_cmd(bash *shpack)
{
	long valueToExit;

	if (shpack->options[1] == NULL || _isnumber(shpack->options[1]))
	{
		valueToExit = _atoi(shpack->options[1]);

		if (valueToExit >= 0 && valueToExit < INT_MAX)
		{
			if (valueToExit > 255)
				valueToExit %= 256;
			if (shpack->options[1] == NULL)
				valueToExit = shpack->exitnum[0];
			free(*(shpack->options));
			free(shpack->options);
			if (*(shpack->envCpy))
				free_doubpoint(*(shpack->envCpy));
			free(shpack);
			exit(valueToExit);
		}
	}

	_error(2, shpack, 2);
	free(shpack->options);
	return (-1);
}
/**
 * _env_cmd - built in command env
 * @shpack: struct containing shell info
 *
 * Return: 1 if succesful
 */
ssize_t _env_cmd(bash *shpack)
{
	char **str;
	int check = 1;

	if (*(shpack->envCpy) == NULL)
	{
		write(2, "Environment is Null, Can't Print it\n", 36);
		shpack->exitnum[0] = 2;
		free(shpack->options);
		return (-1);
	}

	str = *(shpack->envCpy);

	if (shpack->options[1] == NULL)
	{
		for (; str && *str; str++)
		{
			write(STDOUT_FILENO, *str, _strlen(*str));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	else
	{
		_error(0, shpack, 2);
		check = -1;
	}

	free(shpack->options);
	return (check);
}
/**
 * _setenv_cmd - built in command setenv
 * @shpack: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t _setenv_cmd(bash *shpack)
{
	char **newenv;
	char *variable = NULL;
	char *value = NULL;

	if (shpack->options[1])
	{
		variable = shpack->options[1];
		if (!shpack->options[2])
		{
			write(STDERR_FILENO, "Invalid VALUE\n", 14);
			shpack->exitnum[0] = 2;
			free(shpack->options);
			return (-1);
		}
		else
			value = shpack->options[2];

	}
	if (variable == 0)
	{
		write(STDERR_FILENO, "Invalid VARIABLE\n", 17);
		shpack->exitnum[0] = 2;
		free(shpack->options);
		return (-1);
	}

	newenv = _setenv(*(shpack->envCpy), variable, value, shpack);

	if (newenv == 0)
	{
		free(shpack->options);
		return (-1);
	}

	*(shpack->envCpy) = newenv;
	free(shpack->options);
	return (1);
}
/**
 * _unsetenv_cmd - built in command unsetenv
 * @shpack: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t _unsetenv_cmd(bash *shpack)
{
	char **newenv;
	char *variable = NULL;

	if (shpack->options[1])
		variable = shpack->options[1];
	else
	{
		shpack->exitnum[0] = 2;
		write(STDERR_FILENO, "Please provide an argument\n", 27);
		return (free(shpack->options), -1);
	}

	if (variable == 0)
	{
		free(shpack->options);
		return (1);
	}

	newenv = _unsetenv(*(shpack->envCpy), variable, shpack);

	if (newenv == 0 && shpack->unsetnull[0] == 0)
	{
		free(shpack->options);
		shpack->exitnum[0] = 2;
		return (-1);
	}

	*(shpack->envCpy) = newenv;
	free(shpack->options);
	return (1);
}

/**
 * built_ints - checks if cmd is a built in
 * @shpack: struct containing shell info
 *
 * Return: On fail 0
 */
ssize_t built_ints(bash *shpack)
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
		if (!_strcmp(shpack->cmd, ops[x].cmd))
		{
			shpack->errnum[0] = shpack->errnum[0] + 1;
			builtcheck = ops[x].f(shpack);
			if (builtcheck == 1)
				shpack->exitnum[0] = 0;
			return (builtcheck);
		}
	}

	return (0);
}
