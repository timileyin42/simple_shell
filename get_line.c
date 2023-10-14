#include "main.h"

/**
 * call_line - Creating of a space for var for get_line
 * @indexptr: A pointer to the buffer that hold the char
 * @s: size of the line in buffer
 * @buf: The string/input that is being called
 * @b: size of the buffer itself
 */

void call_line(char **indexptr, size_t *s, char *buf, size_t b)
{
	size_t new_size;

	new_size = (b > BUFSIZE) ? b : BUFSIZE;

	if (*indexptr == NULL || new_size > *s)
	{
		*s = new_size;
		*indexptr = buf;
	}
	else
	{
		_strcpy(*indexptr, buf);
		free(buf);
	}
}

/**
 * get_line - Read input fom the user/steam
 * @indexptr: A pointer to the buffer that hold the user input
 * @s: Size of the line in the buffer
 * @user_input: The steam to read
 * Return: The number of bytes store
 */

ssize_t get_line(char **indexptr, size_t *s, FILE *user_input)
{
	int x;
	char *buf;
	char a = 'z';
	static ssize_t input;
	ssize_t u_return;

	if (input == 0)
		fflush(user_input);
	else
		return (-1);
	input = 0;

	buf = malloc(sizeof(char) * BUFSIZE);
	if (buf == 0)
		return (-1);

	for (; a != '\n'; input++)
	{
		x = read(STDIN_FILENO, &a, 1);
		if (x == -1 || (x == 0 && input == 0))
		{
			free(buf);
			return (-1);
		}
		if (x == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buf = _realloc(buf, input, input + 1);
		buf[input] = a;
	}
	buf[input] = '\0';
	call_line(indexptr, s, buf, input);
	u_return = input;
	if (x != 0)
		input = 0;
	return (u_return);
}
