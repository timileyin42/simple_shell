#include "main.h"

/**
 * line_splitting - Function that tokenizes the input string
 * @input: A pointer to the input string.
 * Return: splitted string
 */

char **line_splitting(char *input)
{
	size_t x;
	size_t length;
	char **token, *token1;

	length = TOK_BUFSIZE;
	token = malloc(sizeof(char *) * (length));
	if (token == NULL)
	{
		write(2, ": allocation failled\n", 18);
		exit(98);
	}
	token1 = _strtok(input, TOK_DELIM);
	token[0] = token1;

	while (token != NULL)
	{
		if (x == length)
		{
			length = length + TOK_BUFSIZE;
			token = _realloptr(token, x, sizeof(char *) * length);
			if (token == NULL)
			{
				write(2, ": allocation failed\n", 18)
					exit(98);
			}
		}
		token1 = _strtok(NULL, TOK_DELIM);
		token[x] = token1;
		x++;
	}
	return (token);
}

/**
 * command_splitted - Function that splits command lines accordingly
 *
 * @shell_op: A pointer to the type of data structure
 * @input: Pointer pointing to the the input string
 * Return: 0 to exit, 1 to continue
 */
int command_splitted(bash_shell *shell_op, char *input)
{
	list_div *head_div, *div;
	buf_store *head_store, buf;
	int check;

	head_div = NULL;
	head_store = NULL;

	node_adding(&head_div, &head_store, input);

	div = head_div;
	buf = head_store;

	for (; buf != NULL; buf = buf->next)
	{
		shell_op->input = buf->line;
		shell_op->args = line_splitting(shell_op->input);
		check = han_exec_line(shell_op);
		free(shell_op->args);

		if (check == 0)
			break;

		move_next(&div, buf, shell_op);
	}
	free_sep_list(&head_div);
	free_line_list(&head_store);

	if (check == 0)
		return (0);
	return (1);
}

/**
 * node_adding - Functions that add separators and command lines in the lists
 * @head_div: A double pointer pointing to the head of separator list
 * @head_buf: A pointer pointing to the head of command lines list
 * @input: Pointer to the buffer of input string
 * Return: no return
 */
void node_adding(list_div **head_div, buf_store **head_buf, char *input)
{
	int x;
	char *line;

	input = chars_swapping(input, 0);

	x = 0;
	while (input[x])
	{
		if (input[x] == ';')
			add_sep_node_end(head_div, input[x]);
		if (input[x] == '|' || input[x] == '&')
		{
			add_sep_node_end(head_div, input[x]);
			x++;
		}
	}
	line = _strtok(input, ";|&");
	do {
		line = char_swapping(line, 1);
		add_line_node_end(head_buf, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);
}

/**
 * move_next - Functions that helps go to the next command line stored
 *
 * @div_it: A double pointer that point separator list
 * @store_it: A pointer pointing to command line list
 * @shell_op: A pointer to the data structure
 * Return: always (0)
 */

void move_next(list_div **div_it, buf_store **store_it, bash_shell *shell_op)
{
	int check_list;
	list_div *div;
	buf_store *buf;

	check_list = 1;
	div = *div_it;
	buf = *store_it;

	for (; div != NULL && check_list; div = div->next)
	{
		if (shell_op->mode == 0)
		{
			if (div->separator == '&' || div->separator == ';')
				check_list = 0;
			if (div->separator == '|')
				buf = buf->next, div = div->next;
		}
		else
		{
			if (div->separator == '|' || div->separator == ':')
				check_list = 0;
			if (div->separator == '&')
				buf = buf->next, div = div->next;
		}
	}
	*div_it = div;
	*store_it = buf;
}

/**
 * char_swapping - Functions that helps swaps | and & for non-printed chars
 * @input: A pointer to the input string
 * @check: buffer holding the type of swap
 * Return: swapped string
 */
char *char_swapping(char *input, int check)
{
	int x = 0;

	if (check == 0)
	{
		while (input[x])
		{
			if (input[x] == '|')
			{
				if (input[x + 1] != '|')
					input[x] = 16;
				else
					x++;
			}
			if (input[x] == '&')
			{
				if (input[x + 1] != '&')
					input[x] = 12;
				else
					x++;
			}
			x++;
		}
	}
	else
	{
		x = 0;
		while (input[x])
		{
			input[x] = (input[x] == 16 ? '|' : input[x]);
			input[x] = (input[x] == 12 ? '&' : input[x])
				x++;
		}
	}
	return (input);
}
