#include "main.h"

/**
 * signal_handler - Function that handles ctrl + c in runtime
 * @x: unused value, just for betty
 *
 * Return: No return
 */
void signal_handler(int __attribute__((unused)) x)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * signal_handler1 - handles ctrl + c during cmd exec
 * @x: unused value, just for betty
 *
 * Return: No return
 */
void signal_handler1(int __attribute__((unused)) x)
{
	write(STDOUT_FILENO, "\n", 1);
}
