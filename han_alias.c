#include "holberton.h"


/**
 * add_alias - function that add alias.
 * @head: node tha has the builtin command
 * @name: A pointer to the data structure name
 * @value: value
 * Return: no return
 */

alias *add_alias(alias **head, char *name, char *value)
{
	int flag = 1;
	alias *p = *head;
	alias *new = malloc(sizeof(alias));
	alias *cpy = NULL;

	cpy = *buscar_alias(p, name);
	if (cpy)
	{
		free(cpy->value);
		free(name);
		free(new);
		cpy->value = value;
		return (cpy);
	}
	do {
		if (!p || !(p->next))
		{
			if (!new)
				return (NULL);
			new->name = name;
			new->value = value;
			new->next = NULL;
			if (!p)
			{
				*head = new;
				return (new);
			}
			p->next = new;
			flag = 0;
		}
		else
			p = p->next;
	} while (flag);
	return (new);
}

alias *buscar_alias(alias *head, char *name)
{
	char *input = NULL;

	while (head)
	{
		input = head->name;
		if (_strcmp(input, name))
			return (head);
		head = head->next;
	}
	return (NULL);
}

/**
 * setalias - set alias.
 * @tokens: node tha has the builtin command
 *
 * Return: no return
 */
alias *setalias(char **tokens)
{
	static alias *head;
	char *name = NULL, *value = NULL;
	alias *res = NULL;
	static int flag = 1;

	if (!tokens)
		return (head);
	name = tokens[0];
	value = tokens[1];
	if (flag && !value)
		return (head);
	if (name && !value)
	{
		res = buscar_alias(head, name);
		return (res);
	}
	if (!name && !value)
	{
		return (head);
	}
	if (name && value)
	{
		res = add_alias(&head, name, value);
		return (res);
	}
	return (NULL);
}

/**
 * print_all_alias - show help document of some functions.
 *
 * Return: no return
 */
void print_all_alias(void)
{
	alias *aux = NULL;

	aux = setalias(NULL);
	while (aux)
	{
		print_one_alias(aux->name);
		aux = aux->next;
	}
}

/**
 * _alias - show help document of some functions.
 * @h: node tha has the builtin command
 *
 * Return: 0 or -1
 */
int _alias(bash_shell *h)
{
	char **args = NULL;
	char **tokens = NULL;
	int pos = 1, x = 0;

	args = h->args;
	for  (; args[x]; x++)
		;
	if (x == 1)
	{
		print_all_alias();
		return (0);
	}
	while (pos < x)
	{
		if (_have_value(args[pos]))
		{
			tokens = token_alias(args[pos]);
			setalias(tokens);
			free(tokens);
		}
		else
			print_one_alias(args[pos]);
		pos++;
	}
	return (0);
}
