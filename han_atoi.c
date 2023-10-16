#include "holberton.h"
/**
 * _atoi - This fuction only prints half of a string
 * @s:  is the pointer to the  source array
 * Return: is value of the integer
 */

int _atoi(char *s)
{
	unsigned int aux = 0;
	unsigned int stop = 0;
	int sign = 1, x = 0;
	unsigned int n = 0;
	unsigned int inAn = 0;

	for (x = 0; s[x]; x++)
		if ((s[x] < '0' || s[x] > '9') && (s[x] != '+' && s[x] != '-'))
			return (-1);
	do {
		if (*(s + aux) == '\0')
			stop = 1;
		else
		{
			if (*(s + aux) == '-')
				sign = sign * (-1);
			if ((*(s + aux) > 57 || *(s + aux) < 48) && inAn == 1)
				return (n * sign);
			if (*(s + aux) > 47 && *(s + aux) < 58)
			{
				inAn = 1;
				n = n * 10;
				n = n + (*(s + aux) - 48);
			}
		}
		aux++;
	} while (stop == 0);
	return (n * sign);
}
