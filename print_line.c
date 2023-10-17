#include "holberton.h"

/**
 * print_number - This only check if the character is a digit
 * @n:  is the number of times the character should be printed
 *
 * Return: pointer to the string
 */
char *print_number(int n)
{
	unsigned int t;
	unsigned int aux;
	int aux1;
	unsigned int aux2;
	unsigned int mns = 45;
	char *res = _calloc(30, 1);
	int cnt = 0;

	t = 0;
	aux =  n > 0 ? n : n * (-1);
	aux2 = 10;
	if (n < 0)
	{
		res[0] = mns;
		cnt++;
	}
	n = aux;
	while (aux != 0)
	{
		aux = aux / 10;
		t++;
	}
	for (; t > 1; t--, cnt++)
	{
		aux1 = t - 3;
		for (; aux1 >= 0; aux1--)
		{
			aux2 = 10 * aux2;
		}
		aux = n / aux2;
		n = n % aux2;
		res[cnt] = aux + '0';
		aux2 = 10;
	}
	res[cnt] = (n + '0');
	return (res);
}
