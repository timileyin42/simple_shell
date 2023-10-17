#include "holberton.h"

/**
 * prompt - prints the prompt.
 *
 * Return: no return.
 *
 */
void prompt(void)
{
	int  y, r, p;
	char *prompt = ">:v ";
	char *yellow = "\033[1;33m";
	char *reset = "\033[0m";

	p = r = y = 0;
	for (; reset[r]; r++)
		;
	for (; yellow[y]; y++)
		;
	for (; prompt[p]; p++)
		;
	write(STDIN_FILENO, yellow, y);
	write(STDIN_FILENO, prompt, p);
	write(STDIN_FILENO, reset, r);
}
