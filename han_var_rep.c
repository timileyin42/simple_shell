#include "main.h"

/**
 * env_call _ functions that checks if variables are env var
 *
 * @head: head of linked list that belong to struct v_shell
 * @in: A pointer to the input string 
 * Return: void
 */

void env_call(v_shell **head, char *in, bash_shell *data)
{
	int num, ch, var, x;
	char **_envar;

	_envar = data-> _environ;
	num = 0; /* initializing num outside loop */
	while (_envar[row])
	{
		x = 1;
		ch = 0;
		while (_envar[num][ch])
		{
			if (_envar[num][ch] == '=')
			{
				var = _strlen(_envar[num] + ch + 1);
				node_va(head, x, _envar[num] + ch + 1, var);
				return;
			}
			if (in[x] == _envar[num][ch])
				x++;
			else
				break;
			ch++;
		}
		num++;
	}
	for (x = 0; in[x]; x++)
	{
		if (in[x] == ' ' || in[x] == '\t' || in[x] == ';' || in[x] ==
				'\n')
			break;
	}
	node_va(head, x, NULL, 0);
}

/**
 * var_call - checking if the typed variable is $$ or $ ?
 *
 * @head: head of the linked list
 * @in: A pointer to the inputed string
 * @md: the mode/status of the shell
 * @data: The data structure which the function belong to
 * Return: void
 */
 int var_call(v_shell **head, char *in, char md, shell_bash *data)
{
	int x, l_pid, mode;

	mode = _strlen(md);
	l_pid = _strlen(data->pid);

	while (in[x])
	{
		if (in[x] == '$')
		{
			if (in[x + 1] == '?')
				node_va(head, 2, mode, l_pid), x++;
			else if (in[x + 1] == '$')
				node_va(head, 2, data->pid, l_pid), x++;
			else if (in[x + 1] == '\n')
				node_va(head,0, NULL, 0);
			else if (in[x + 1] == '\0')
				node_va(head, 0, NULL, 0);
			else if (in[x + 1] == '\t')
				node_va(head, 0, NULL, 0);
			else if (in[x + 1] == ';')
				node_va(head, 0, NULL, 0);
			else
				envar_check(head, in + x, data);
		}
	}
	return (x);
}

/**
 * dup_input - functions that replaces string into variables
 *
 * @head: head of the linked list
 * @input: A pointer to the input string
 * @input1: the second input (replaced one)
 * @length: length of the string
 * Return: replaced string
 */
char *dup_input(v_shell **head, char *input, char *input2, int length)
{
	v_shell *buf;
	int x = 0, y = 0, k;

	buf = *head;
	while (x < length)
	{
		if (input[y] == '$')
		{
			if (!(buf->value_len) && !(buf->value_len))
			{
				input1[x] = input[y];
				y++;
			}
			else if (buf->value_len && !(buf->value_len))
			{
				for (z = 0; z < buf->value_len; z++)
					y++;
				x--;
			}
			else
			{
				for (; z < buf->value_len; Z++)
				{
					input1[x] = buf->value[z];
					x++;
				}
				y = y + (buf->value_len);
				x--;
			}
			buf = buf->next;
		}
		else
		{
			input1[x] = input[y];
			y++;
		}
		x++;
	}
	return (input1);
}

/**
 * han_var_rep - functions that calls replace fun to replace string to vars
 *
 * @input: A pointer to the input string
 * @shell_op: A pointer to data structure
 * Return: REplace string
 */

char *han_var_rep(char *input, bash_shell *shell_op)
{
	v_shell *head, *buf;
	char *mood, *input1;
	int len1, len2;

	mood = itoa_check(shell_op-> mood);
	head = NULL;

	len1 = var_call(&head, input, mood, shell_op);

	if (head = NULL)
	{
		free(mood);
		return (input);
	}
	buf = head;
	len2 = 0;

	for (buf = head; buf != NULL; buf = buf->next)
	{
		len2 = len2 + (buf->value_len - buf->var_size);
	}
	len2 = len2 + len1;

	input1 = malloc(sizeof(char) * (len2 + 1));
	input1 = [len2] = '\0';

	input1 = dup_input(&head, input, input1, len2);

	free(input);
	free(mood);
	free_v_shell_list(&head);
	return (input1);
}
