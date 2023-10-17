#include <unistd.h>
#include "shell.h"

/**
 * signal_handler - handles ctrl + c in runtime
 * @x: unused value, just for betty
 *
 * Return: No return
 */
void signal_handler(int x)
{
	(void) x;
	write(1, "\n$ ", 3);
}
/**
 * signal_handler2 - handles ctrl + c during cmd exec
 * @x: unused value, just for betty
 *
 * Return: No return
 */
void signal_handler2(int x)
{
	(void) x;
	write(1, "\n", 1);
}
