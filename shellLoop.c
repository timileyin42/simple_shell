#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include "shell.h"
/**
 * getParameters - obtains parameters from buffer of prompt
 * @raw_buffer: raw_buffer
 * @shpack: struct containing shell info
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char **getParameters(char *raw_buffer, hshpack *shpack)
{
	char **buffer, *cp_raw_buffer;
	ssize_t cnt = 0, i = 0;

	cp_raw_buffer = _strdup(raw_buffer);
	if (!cp_raw_buffer)
	{
		_error(7, shpack, 1);
		exit(-1);
	}

	if (_strtok(cp_raw_buffer, " \n"))
		cnt++;
	else
	{
		free(cp_raw_buffer);
		return (NULL);
	}
	while (_strtok(NULL, " \n"))
		cnt++;

	free(cp_raw_buffer);
	buffer = malloc(sizeof(char *) * (cnt + 1));
	if (!buffer)
	{
		_error(7, shpack, 1);
		exit(-1);
	}
	buffer[0] = _strtok(raw_buffer, " \n");
	for (i = 1; i < cnt && buffer[i - 1]; i++)
		buffer[i] = _strtok(NULL, " \n");

	if (!buffer[i - 1])
	{
		free_doubpoint(buffer);
		return (NULL);
	}

	buffer[i] = NULL;
	return (buffer);
}
