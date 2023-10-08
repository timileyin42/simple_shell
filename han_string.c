#include "main.h"

/**
 * _strcpy - functions that copy all the string pointed to by shell.
 * @dest: A pointer to the destination of the copied string
 * @src: A pointer to the type of char, as well as the source of the string
 * Return: The destination.
 */

char *_strcpy(char *dest, char *src)
{
	size_t x = 0;

	while (src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}

	dest[x] = '\0';
	return (dest);
}

/**
 * _strchr - functions that locates a charcater in a string
 * @s: A pointer to the char string to locate
 * @c: the character to locate
 * Return: The pointer to the first occurence of the char c.
 */

char *_strchr(char *s, char c)
{
	unsigned int x = 0;

	while (*(s + x) != '\0')
	{
		if (*(s + x) == c)
		{
			return (s + x);
		}
		x++;
	}
	if (*(s + x) == c)
	{
		return (s + x);
	}
	return ('\0');
}

/**
 * _strcat - functions that concatenate two strings
 * @dest: A pointer to the destination of thecopied string
 * @src: A pointer to the type of const char, pointing to the source string
 * Return: The destination of the string concatenated
 */

char *_strcat(char *dest, const char *src)
{
	int x;
	int y;

	while (dest[x] != '\0)
	{
		x++;
	}

	while (src[y] != '\0')
	{
		dest[x] = src[y];
		x++;
		y++;
	}

	dest[x] = '\0';

	return (dest);
}

/**
 * _strspn - Functions that get the length of a prefix substring.
 * @s: the source to strt the checking
 * @allow: A pointer that point to the allow length/ bytes.
 * Return: The number of allowed bytes
 */

int _strspn(char *s, char *allow)
{
	int x = 0;
	int y, check;

	while (*(s + x) != '\0')
	{
		check = 1;
		y = 0;
		while (*(allow + y) != '\0')
		{
			if (*(s + x) == *(allow + y))
			{
				check = 0;
				break;
			}
			y++;
		}
		if (check == 1)
			break;
		x++;
	}
	return (x);
}

/**
 * _strcmp - Function that compares two strings.
 * @s: A pointer to the first char string to compare
 * @s1: A pointer to the second char string to compare
 * Return: Always (0).
 */

int _strcmp(char *s, char *s1)
{
	int x = 0;
	while (s[x] == s1[x] && s[x])
	{
		x++;
	}
	if (s[x] > s1[x])
	{
		return (1);
	}
	if (s[x] < s1[x])
	{
		return (-1);
	}
	return (0);
}
