#include <limits.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 * _exit_cmd - built in command exit
 * @shpack: struct containing shell info
 *
 * Return: -1 if error
 */
ssize_t _exit_cmd(hshpack *shpack)
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
ssize_t _env_cmd(hshpack *shpack)
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
			write(1, *str, _strlen(*str));
			write(1, "\n", 1);
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
ssize_t _setenv_cmd(hshpack *shpack)
{
	char **newenv;
	char *variable = NULL;
	char *value = NULL;

	if (shpack->options[1])
	{
		variable = shpack->options[1];
		if (!shpack->options[2])
		{
			write(2, "Invalid VALUE\n", 14);
			shpack->exitnum[0] = 2;
			free(shpack->options);
			return (-1);
		}
		else
			value = shpack->options[2];

	}
	if (variable == 0)
	{
		write(2, "Invalid VARIABLE\n", 17);
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
ssize_t _unsetenv_cmd(hshpack *shpack)
{
	char **newenv;
	char *variable = NULL;

	if (shpack->options[1])
		variable = shpack->options[1];
	else
	{
		shpack->exitnum[0] = 2;
		write(2, "Please provide an argument\n", 27);
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
ssize_t built_ints(hshpack *shpack)
{
	b_ins ops[] = {
		{"exit", _exit_cmd},
		{"env", _env_cmd},
		{"setenv", _setenv_cmd},
		{"unsetenv", _unsetenv_cmd},
		{"cd", _cd_cmd},
		{"help", _help_cmd}
	};

	int i = 6, builtcheck; /* lenght of ops array */

	while (i--)
		if (!_strcmp(shpack->cmd, ops[i].cmd))
		{
			shpack->errnum[0] += 1;
			builtcheck = ops[i].f(shpack);
			if (builtcheck == 1)
				shpack->exitnum[0] = 0;
			return (builtcheck);
		}

	return (0);
}
