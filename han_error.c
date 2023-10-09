#include "main.h"

/**
 * char_cmp - func that count the repeated char
 * @command: The string  input to the terminal
 * @x: index of the func
 * Return: repeated char
 */

int char_cmp(const char *command, int x)
{
	if (*(command - 1) == *command)
		return (char_cmp(command - 1, x + 1));

	return (x);
}

/**
 * error_finder - functions that fimd all the error in the terminal
 *
 * @command: the string input
 * @x: index of the func
 * @end: the last char read
 * return: index of error, 0, if otherwise
 */

int error_finder(char *command, int x, char end)
{
	int count;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*command == ' ' || *command == 't')
		return (error_finder(command + 1, x + 1, end));

	if (*command == ';')
		if (end == '|' || end == '&' || end == ';')
			return (x);
	if (*command == '|')
	{
		if (end == ';' || end == '&')
			return (x);

		if (end == '|')
		{
			count = char_cmp(command, 0);
			if (count == 0 || count > 1)
				return (x);
		}
	}

	if (*command == '&')
	{
		if (end == ';' || end == '|')
			return (x);

		if (end == '&')
		{
			count = char_cmp(command, 0);
			if (count == 0 || count > 1)
				return (x);
		}
	}
	return (error_finder(command + 1, x + 1, *command));
}

/**
 * set_char - func that find the first char in the index
 *
 * @command: the string input
 * @x: index of the func
 * Return: 1 for error encounter, 0 if oterwise.
 */

int set_char(char *command, int x)
{
	*x = 0;

	while (command[*x])
	{
		if (command[*x] == ' ' || input[*x] == '\t')
		{
			(*x)++;
			continue;
		}

		if (command[*x] == ';' || command[*x] == '|' || command[*x] == 
				'&')
		{
			return (-1);
		}

		break;
	}

	return (0);
}

/**
 * han_error_print - func that printout when it detect error
 *
 * @shell_op: data structure
 * @command: the string input to the buffer
 * @x: index of the error to be print
 * @read: it control and direct te error message
 * Return: void
 */
void han_error_print(bash_shell *shell_op, char *command, int x, int bool)
{
	char *output, *output1, *output2, *error, *loop;
	int legnth;

	switch (command[x])
	{
		case ';':
			output = (bool == 0) ? (command[x + 1] == ';' ? ";;" : 
					";") : (command[x - 1] == ';' ? ";;" :
						";");
			break;

		case '|':
			output = (command[x + 1] == '|') ? "||" : "|";
			break;

		case '&':
			output = (command[x + 1] == '&') ? "&&" : "&";
			break;

		default:
			output = ""; /* if none of the case meet */
	}

	output1 = ": Error occur: \"";
	output2 = "\" undefined input \n";
	loop = itoa_check(shell_op->loop);
	length = _strlen(shell_op->av[0]) + _strlen(loop);
	length = length + _strlen(output) + _strlen(output1) + _strlen(output2)
		+ 2;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(loop);
		return;
	}

	_strcpy(error, shell_op->av[0]);
	_strcat(error, ": ");
	_strcat(error, loop);
	_strcat(error, output);
	_strcat(error, output1);
	_strcat(error, output2);
	_strcat(error, "\0");

	write(2, error, length);
	free(error);
	free(loop);
}
