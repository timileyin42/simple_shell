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
	long i = 0;
	long res = 1;

	for (i = 0; i < pot; i++)
		res *= base;

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
	long i = 0;
	long k = 0;
	long len = 0;
	unsigned long result = 0;
	long toReturn = 0;
	long minus = 0;
	long offset = 48;

	if (!s)
		return (0);

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (*(s + i) >= 48 && *(s + i) <= 57)
			len++;
		else if (len != 0)
			break;

		if (*(s + i) == '-')
			minus++;
	}

	for (i--; len > 0; i--, k++, len--)
		result +=  (*(s + i) - offset) * _pow(10, k);

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
	int i = 0;
	int equal = 0;

	for (i = 0; (*(s1 + i) || *(s2 + i)) && !equal; i++)
		if (*(s1 + i) != *(s2 + i))
			equal = *(s1 + i) - *(s2 + i);

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
	for (; *s; s++)
		if (!_isdigit(*s))
			return (0);
	return (1);
}
