#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include "shell.h"

/**
 * _strtok - tokenizes a string based on a delimiter
 *
 * @str: string to operate
 * @delim: delimiter
 *
 * Return: pointer to string
 * or NULL if there is no match
 *
 */
char *_strtok(char *str, const char *delim)
{
	const char *org = delim;
	int isEqual = 1, isGetInto = 0;
	static char *step, *stepNull;
	static int isEnd;

	if (str)
		isEnd = 0;
	if (isEnd)
		return (NULL);
	step = (str) ? str : (stepNull + 1);
	if (str)
		stepNull = str;
	else
		str = step;
	while (*str && isEqual)
	{
		isEqual = 0;
		for (delim = org; *delim; delim++)
			if (*str == *delim)
				isEqual = 1;
		str = (!isEqual) ? str : str + 1;
		isEnd = (*str) ? 0 : 1;
		if (isEnd)
			return (NULL);
	}
	step = str;
	while (*str && !isEqual)
	{
		isEqual = 0;
		for (delim = org; *delim; delim++)
			if (*str == *delim)
			{
				isGetInto = 1, isEqual = 1;
				isEnd = (*(str + 1)) ? 0 : 1, *str = '\0';
			}
		str = (isEqual) ? str : str + 1;
		if (!isGetInto && !*str)
			isEnd = 1;
	}
	return (stepNull = str, step);
}
