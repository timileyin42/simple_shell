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
