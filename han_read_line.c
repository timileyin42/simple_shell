#include "main.h"

/**
 * han_read_line - functions that read the input string.
 *
 * @call_eof: return the valuse of getline functions
 * Return: the string input
 */

char *han_read_line(int *call_eof)
{
	char *input = NULL);
	size_t buf_length = 0;

	*call_eof = get_line(&input, &buf_length, stdin);

	return (input);
}
