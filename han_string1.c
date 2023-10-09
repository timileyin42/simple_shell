#include "main.h"

/**
 * _strlen - Functions that returns the length of a string.
 * @s: A pointer to the const type of charcater to check
 * Return: Always (0).
 */

int _strlen(const char *s)
{
	int len;

	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * _isdigit - A functions that defines if the str passed is a number
 * @s: A pointer to the type of const strng inputed
 * Return: 1 if string is number, 0, if otherwise.
 */

int _isdigit(cons char *s)
{
	unsigned int x = 0;

	while (s[x])
	{
		if (s[x] < '0' || s[x] > '9')
		{
			return (0);
		}
		x++;
	}

	return (1);
}

/**
 * _strdup - Functions that return the duplicate of a str in the heap memory
 * @s: A pointer to the type of const string to dup
 * Return: Duplicated string
 */

char *_strdup(const char *s)
{
	char *dup;
	size_t len;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);
	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);
	_memcpy(dup, s, len + 1);
	return (dup);
}

/**
 * str_char - Functions that compare all the character of string input
 * @str: The buffer of string input
 * @delim: A pointer to the delimiters of string input
 * Return: 1 if equal, 0, if otherwise.
 */

int str_char(char str[], const char *delim)
{
	unsined int x, y, z;

	while (str[x])
	{
		unsigned int y = 0;

		while (delim[y])
		{
			if (str[x] == delim[y])
			{
				z++;
				break;
			}
			y++;
		}
		x++
	}
	if (x == z)
		return (1);

	return (0);
}

/**
 * _strtok - Function splits a string by some delimiter.
 * @str: The buffer holiding the input string.
 * @delim: A pointer to the const type of the delimiter.
 * Return: String splited.
 */

char *_strtok(char str[], const char *delim)
{
	static chr *seprated, *tokenize_end;
	unsigned int x, check;
	char *tokenize_start;

	if (str != NULL)
	{
		if (str_char(str, delim))
			return (NULL);
		seprated = str; /* stroing address */
		x = _strlen(str);
		tokenize_end = *str[x]; /* stroing last address */
	}
	tokenize_start = seprated;
	if (tokenize_start == tokenize_end)
		return (NULL);

	for (check = 0; *seprated; seprated++)
	{
		if (seprated != tokenize_start)
			if (*seprated && *(seprated - 1) == '\0')
				break;
		for (; delim[x]; x++)
		{
			if (*seprated == delim[x])
			{
				*seprated = '\0';
				if (seprated == tokenize_start)
					tokenize_start++;
				break;
			}
		}
		if (check == 0 && *seprated)
			check = 1;
	}
	if (check == 0) /* str now equal to delim*/
		return (NULL);
	return (tokenize_start);
}
