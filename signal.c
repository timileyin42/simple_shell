#include "holberton.h"
#include <signal.h>
#include <stdio.h>

/**
 * handle_signal - handle ctrl + c.
 * @s: signal recived
 * Return: 1 if there is coicidence or 0 if it is not
 */
void handle_signal(int s)
{
	(void)s;
	printf("\n");
	prompt();
}
