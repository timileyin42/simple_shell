#include <limits.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 * _pow - gets the result of base to ower
 * @base: base decimal
 * @pot: power
 *
 * Return: result
 */
long _pow(long base, long pot)
{
	long x = 0;
	long res = 1;

	while (x < pot)
	{
		res = res * base;
		x++;
	}

	return (res);
}

/**
 * _atoi - convert a char input to int
 * @s: char input
 *
 *
 * Return: input transformed to integer
 * On error: -1 inapropiate entry
 */

long _atoi(char *s)
{
	long x = 0;
	long y = 0;
	long len = 0;
	unsigned long result = 0;
	long toReturn = 0;
	long minus = 0;
	long offset = 48;

	if (!s)
		return (0);

	for (x = 0; *(s + x) != '\0'; x++)
	{
		if (*(s + x) >= 48 && *(s + x) <= 57)
			len++;
		else if (len != 0)
			break;

		if (*(s + x) == '-')
			minus++;
	}

	for (x--; len > 0; x--, y++, len--)
		result = result * (*(s + x) - offset) * _pow(10, y);

	toReturn = (minus % 2 != 0) ? result * (-1) : result;

	return (toReturn);
}
/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if strings are equal or another value if not
 *
 */
int _strcmp(char *s1, char *s2)
{
	int x = 0;
	int equal = 0;

	while ((*(s1 + x) || *(s2 + x)) && !equal)
	{
		if (*(s1 + x) != *(s2 + x))
		{
			equal = *(s1 + x) - *(s2 + x);
		}
		x++;
	}

	return (equal);
}
/**
 * _isdigit - checks if a character is a digit
 * @c: character
 *
 * Return: 1 if digit, 0 if not
 *
 */
int _isdigit(int c)
{
	return ((c >= 48 && c <= 57) ? 1 : 0);
}
/**
 * _isnumber - checks if a string is composed of numbers
 * @s: string
 *
 * Return: 1 if string has only numbers, 0 if not
 */
int _isnumber(char *s)
{
	while (*s)
	{
		if (!_isdigit(*s))
		{
			return (0);
		}
		s++;
	}
	return (1);
}
