#include "shell.h"


/**
 * add_alias - add alias.
 * @head: node tha has the builtin command
 * @name: name
 * @value: value
 * Return: no return
 */

alias *add_alias(alias **head, char *name, char *value)
{
	int flag = 1;
	alias *p = *head;
	alias *new = malloc(sizeof(alias));
	alias *cpy = NULL;

	cpy = buscar_alias(p, name);
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

/**
 * _strcmp - compare string.
 * @s1: string 1
 * @s2: string 1
 * Return: no return
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0;

	for (; s1[i] && s2[j]; i++, j++)
		if (s1[i] != s2[j])
			return (0);
	if (!s1[i] && !s2[j])
		return (1);
	return (0);
}

/**
 * buscar_alias - buscar alias
 * @head: head
 * @name: name
 *
 * Return: no return
 */
alias *buscar_alias(alias *head, char *name)
{
	char *cpyname = NULL;

	while (head)
	{
		cpyname = head->name;
		if (_strcmp(cpyname, name))
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
 * _strlen - longitud string.
 * @str: pointer to string
 *
 * Return: size
 */
int _strlen(char *str)
{
	int i = 0;

	if (str)
	{
		for (i = 0; str[i]; i++)
			;
		return (i + 1);
	}
	return (-1);
}
