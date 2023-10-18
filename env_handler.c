#include "main.h"

/**
 * _getenv - Function that get environment variable
 *
 * @name: name of environmental variable
 * @env: current environment
 *
 * Return: pointer to the value in the environment,
 * or NULL if there is no match
 *
 */
char *_getenv(const char *name, char **env)
{
	int x, y, check, z = 0;

	if (env == NULL)
		return (NULL);

	while (name[z] != 0)
		z++;

	for (x = 0; env[x] != 0; x++)
	{
		for (check = 0, y = 0; y < z && env[x][y] != 0; y++)
			if (env[x][y] == name[y])
				check++;
		if (check == z && env[x][check] == '=')
			return (env[x]);
	}

	return (NULL);
}
