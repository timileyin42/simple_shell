#include "main.h"

/**
 * han_itoa - Function that helps convert int to string.
 * @d: buffer holding the type of number
 * Return: data type of string.
 */

char *han_itoa(int d)
{
	unsigned int decimal;
	int length = han_len(d);
	char *store;

	store = malloc(sizeof(char) * (length + 1));
	if (store == 0)
		return (NULL);

	*(store + length) = '\0';

	if (d < 0)
	{
		decimal = d * -1;
		store[0] = '-';
	}
	else
	{
		decimal = d;
	}
	length--;
	while (decimal > 0)
	{
		*(store + length) = (decimal % 10) + '0';
		decimal /= 10;
		length--;
	}
	return (store);
}

/**
 * get_len - Function that helps get the length of a number.
 * @i: buffer holding the number to count.
 * Return: Length of a number
 */

int get_len(int i)
{
	int length = 1;
	unsigned int dec;

	if (i < 0)
	{
		length++;
		dec *= -1;
	}
	else
	{
		dec = i;
	}
	for (; dec > 9; dec /= 10)
	{
		length++;
	}
	return (length);
}
/**
 * _atoi - Functon that helps convert a string t integer.
 * @c: A pointer to the buffer holding the string to convert
 * Return: integer.
 */

int _atoi(char *c)
{
	unsigned int length = 0, value = 0, dec = 0, x = 1, y = 1, z;

	while (*(c + length) != '\0')
	{
		if (value > 0 && (*(c + length) < '0' || *(c + value) > '9'))
			break;
		if (*(c + length) == '-')
			x = x * -1;
		if ((*(c + length) >= '0') && (*(c + length) <= '9'))
		{
			if (value > 0)
				y = y * 10;
			value++;
		}
		length++;
	}
	z = length - value;
	while (z < length)
	{
		dec += ((*(c + z) - 48) * y);
		y = y / 10;
		z++;
	}
	return (dec * x);
}
