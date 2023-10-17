#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#define MAX 500

/**
 * getpath - get current path
 *
 * Return: no return
 */

char *getpath(void)
{

	static int flag;
	static char *path;

	if (!flag)
	{
		path = _calloc(500, 1);
		if (path == NULL)
			return (0);
		path = getcwd(path, 500);
		flag = 1;
	}
	return (path);
}

/**
 * lukeSkywalker - return 0.
 *
 * Return: no return
 */
int lukeSkywalker(void)
{
	return (0);
}

/**
 * aredots - Function that help filter (.. /).
 * @path: pointer to path
 * @pos: position in buffer to verify if it is . . and /
 * @size: size of buffer
 * Return: 0 or 1
 */
int aredots(char *path, int pos, int size)
{
	if (path[pos] && path[pos + 1] && path[pos + 2])
	{
		if (path[pos] == '/' && path[pos + 1] == '.'
		    && path[pos + 2] == '.')
		{
			if ((pos + 3) <= size)
			{
				if ((path[pos + 3]) == 0 ||
				    (path[pos + 3]) == '/')
					return (1);
			}
		}
	}
	return (0);
}

/**
 * filtro1 - delete extra /.
 * @path: pointer to path
 *
 * Return: no return
 */
char *filtro1(char *path)
{
	char *filter = NULL;
	int y = 0, seek = 0, x = 0;

	for (; path[y]; x++)
		;
	filter = _calloc(y + 1, sizeof(char));
	for (; path[x]; x++)
	{
		if (path[x] == '/')
		{
			if (path[x + 1] == 0)
				break;
			if ((x + 1 <= y) && path[x + 1] == '/')
				continue;
			filter[seek] = path[x];
			seek++;
		}
		else
		{
			filter[seek] = path[x];
			seek++;
		}
	}
	return (filter);
}

/**
 * filtro2 - if we have two points after directory .
 * @filter: pointer to the buffer
 *
 * Return: pointer to the copy path
 */
char *filtro2(char *filter)
{
	char *cpypath = NULL;
	int y = 0, pos = 0, x = 0, cnt = 0;

	for (; filter[y]; y++)
		;
	cpypath = _calloc(y + 1, sizeof(char));

	for (x = 0; x <= y && filter[x]; x++)
	{
		if (x == 0 && aredots(filter, x, y))
		{
			x = x + 2;
			continue;
		}
		pos = nextdir(filter, x);
		if (pos == -1)
		{
			for (; filter[x]; x++, cnt++)
				cpypath[cnt] = filter[x];
			break;
		}
		if (aredots(filter, pos, y))
		{
			x = pos + 2;
			continue;
		}
		for (; x <= pos && filter[x]; x++, cnt++)
			cpypath[cnt] = filter[x];
		x--;
	}
	return (cpypath);
}
