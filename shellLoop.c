#include "main.h"

/**
 * parameter_fun - Function that helps obtains parameters from buffer of prompt
 * @raw_buffer: raw_buffer
 * @bash_s: struct containing shell info
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char **parameter_fun(char *raw_buffer, bash *bash_s)
{
	char **buffer, *cp_buffer;
	ssize_t len = 0, x = 0;

	cp_buffer = _strdup(raw_buffer);
	if (cp_buffer == NULL)
	{
		error_fun(7, bash_s, 1);
		exit(-1);
	}

	if (_strtok(cp_buffer, " \n"))
		len++;
	else
	{
		free(cp_buffer);
		return (NULL);
	}
	while (_strtok(NULL, " \n"))
		len++;

	free(cp_buffer);
	buffer = malloc(sizeof(char *) * (len + 1));
	if (buffer == NULL)
	{
		error_fun(7, bash_s, 1);
		exit(-1);
	}
	buffer[0] = _strtok(raw_buffer, " \n");
	for (x = 1; x < len && buffer[x - 1]; x++)
		buffer[x] = _strtok(NULL, " \n");

	if (!buffer[x - 1])
	{
		free_pointer(buffer);
		return (NULL);
	}

	buffer[x] = NULL;
	return (buffer);
}
