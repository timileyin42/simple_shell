#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 * rev_str - Reverses a string
 * @s: string to reverse
 *
 * Return: Nothing
 */
void rev_str(char *s)
{
	int i = 0, j = 0, l;
	char tmp;

	while (s[i])
		i++;
	l = i / 2, i = i - 1;
	while (i >= l)
	{
		tmp  = s[j];
		s[j] = s[i];
		s[i] = tmp;
		i--, j++;
	}
}
/**
 * blen - obtains length of number in base
 *
 * @n: number
 * @base: base of number
 *
 * Return: length of number
 */
int blen(unsigned long int n, unsigned long int base)
{
	unsigned long int i, neg = 0;

	for (i = 0; n > 0; i++)
		n = n / base;
	return (i + neg);
}
/**
 * _itoa - converts an integer to string
 *
 * @n: number
 *
 * Return: pointer to string
 */
char *_itoa(int n)
{
	unsigned long int i = 0, base = 10;
	char *str;

	if (n != 0)
		str = malloc(blen(n, base) + 1);
	else
		str = malloc(2), str[i] = '0', i++;

	if (str == 0)
		return (0);

	for (; n > 0; i++)
	{
		str[i] = (n % base) + '0';
		n = n / base;
	}
	str[i] = '\0';
	rev_str(str);
	return (str);
}

char *_error2(int errn, char *conc2, char *option);
/**
 * _error - creates a string with error line
 * @errn: number corresponding to type of error
 * @shpack: struct containing shell information
 * @exnum: value of exit the shell should have
 *
 * Return: 0 success, -1 fail
 */
int _error(int errn, hshpack *shpack, int exnum)
{
	/**
	 * 0 - file or cmd not found , 1 - permission denied, 2 - illegal exit number
	 * 3 - setenv error,         , 4 - can´t cd         , 5 - invalid option cd
	 * 6 - help _error           , 7 - memory allocation, 8 - Alias Error
	 **/
	int count = shpack->errnum[0], l = 0;
	char *cmd = shpack->cmd, **option = shpack->options;
	char *shelln = shpack->hshname;
	char *nstring, *conc1, *conc2, *colspace = ": ";
	char *err[] = {
		"not found", "Permission denied", "Illegal number",
		"name is NULL, points to string of len 0, or has an '=' char.",
		"can't cd to ", "Illegal option ", "Help command error",
		"Error allocating memory", "Wrong Alias",
		NULL
	};

	conc1 = str_concat(shelln, colspace);
	if (!conc1) /*hsh: */
		return (write(2, "Memory Error", 22), -1);

	if (errn == 7) /* Alloc Error */
	{
		conc2 = str_concat(conc1, err[errn]); /*hsh: count: error*/
		if (!conc2)
			return (free(conc1), write(2, "Memory Error", 22), -1);
		free(conc1);
		while (conc2[l] != 0)
			l++;
		write(2, conc2, l), write(2, "\n", 1);
		free(conc2);
		return (0);

	}

	nstring = _itoa(count);
	if (!nstring)  /* number to string */
		return (free(conc1), write(2, "Memory Error", 22), -1);

	conc2 = str_concat(conc1, nstring);
	if (!conc2) /*hsh: count*/
	{
		write(2, "Memory Error", 22);
		return (free(conc1), free(nstring),  -1);
	}
	free(conc1), free(nstring);

	conc1 = str_concat(conc2, colspace);
	if (!conc1) /*hsh: count: */
		return (free(conc2), write(2, "Memory Error", 22), -1);

	free(conc2);
	conc2 = str_concat(conc1, cmd);
	if (!conc2) /*hsh: count: cmd*/
		return (free(conc1), write(2, "Memory Error", 22), -1);
	free(conc1);

	conc1 = str_concat(conc2, colspace);
	if (!conc1) /*hsh: count: cmd: */
		return (free(conc2), write(2, "Memory Error", 22), -1);
	free(conc2);

	conc2 = str_concat(conc1, err[errn]);
	if (!conc2) /*hsh: count: cmd: error*/
		return (free(conc1), write(2, "Memory Error", 22), -1);
	free(conc1);

	if (errn > 1 && errn < 6 && errn != 3)
		conc2 = _error2(errn, conc2, option[1]);
	if (conc2 == NULL)
	{
		write(2, "Memory Error", 22);
		return (-1);
	}

	while (conc2[l] != 0)
		l++;
	write(2, conc2, l), write(2, "\n", 1);
	free(conc2);
	shpack->exitnum[0] = exnum;
	return (0);

}
/**
 * _error2 - extra modes for error generation
 * @errn: number corresponding to type of error
 * @conc2: error part from _error
 * @option: cmd option thaat
 *
 * Return: pointer to string
 */
char *_error2(int errn, char *conc2, char *option)
{
	/**
	 * 0 - file or cmd not found , 1 - permission denied, 2 - illegal exit number
	 * 3 - setenv error,         , 4 - can´t cd         , 5 - invalid option cd
	 * 6 - help _error           , 7 - memory allocation, 8 - Alias Error
	 **/
	char *conc1, *colspace = ": ";

	if (errn == 2) /* exit error */
	{

		conc1 = str_concat(conc2, colspace);
		if (!conc1) /*hsh: count: cmd: error: */
		{
			write(2, "Memory Error", 22);
			return (free(conc2), NULL);
		}
		free(conc2);

		conc2 = str_concat(conc1, option);

		if (!conc2) /*hsh: count: cmd: error: option*/
		{
			write(2, "Memory Error", 22);
			return (free(conc1), NULL);
		}
		free(conc1);
	}
	if (errn > 3) /* Errors with options at end */
	{
		conc1 = str_concat(conc2, option);
		if (!conc1) /*hsh: count: cmd: error option*/
		{
			write(2, "Memory Error", 22);
			return (free(conc2), NULL);
		}
		free(conc2);
		return (conc1);
	}
	return (conc2);

}
