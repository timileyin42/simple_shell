#include "main.h"

/**
 * rev_string - Functions that reverse a string
 * @s: A pointer to the type of char string input
 * Return: Always (0)
 */

void rev_string(char *s)
{
	int length = 0, x, y;
	char *str, temp;

	while (length >= 0)
	{
		if (s[length] == '\0')
			break;
		length++;
	}
	str = s;

	x = 0;
	while (x < (length - 1))
	{
		y = x + 1;
		while (y > 0)
		{
			temp = *(str + y);
			*(str + y) = *(str + (y - 1));
			*(str + (y - 1)) = temp;
			y--;
		}
		x++;
	}
}

/**
 * _strcmp - Function that helps compare two string
 * @s1: A pointer to the type of the first char to compared
 * @s2: A pointer to the second type of char to compared
 * Return: Always (void)
 */

int _strcmp(char *s1, char *s2)
{
	int x = 0;

	while (s1[x] == s2[x] && s1[x])
	{
		x++;
	}

	if (s1[x] > s2[x])
	{
		return (1);
	}

	if (s1[x] < s2[x])
	{
		return (-1);
	}
	return (0);
}

/**
 * _strspn - Function that helps get the length of a prefix substring.
 * @s: A pointer to the buffer holding where to start count
 * @allow: A pointer to the allowed bytes/string
 * Return: The number of allowed bytes
 */

int _strspn(char *s, char *allow)
{
	int x = 0, y, check;

	while (s[x] != '\0')
	{
		check = 1;
		y = 0;

		while (allow[y] != '\0')
		{
			if (s[x] == allow[y])
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
