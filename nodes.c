#include "holberton.h"
#include <stdio.h>

/**
 * istoken - verfy operators.
 * @c: character to verify
 * Return: 1 if there is coicidence or 0 if it is not
 */
int istoken(char c)
{
	int x = 0;
	char tokens[] = {'&', '|', '\0', ';', '\n',  -1};

	while (tokens[x] != -1)
	{
		if (tokens[x] == c)
			return (1);
		x++;
	}
	return (0);
}

/**
 * crear_name - copy argv[0] to display in errors
 * @name: pointer to name of command
 *
 * Return: pointer to command name
 */
char *crear_name(char  *name)
{
	int x = 0;
	char *newname;

	x = _strlen(name);
	newname = _calloc(l, sizeof(char));
	for (; name[x]; x++)
		newname[x] = name[x];
	return (newname);
}
/**
 * _getargs  - create a linked list that contains all arguments.
 * @buf: buffer with the string
 * @pos: pointer tu the actual buffer position
 * @name: pointer to name of commands
 * Return: a pointer to the linked list
 */
bash_shell *_getargs(char *buf, ssize_t *pos, char *name)
{
	ssize_t p = 0;
	unsigned int flag = 0;
	int sp = 0, id = 0, aux = 0;
	command_t *head = NULL;
	char **args = NULL;
	char *n = NULL;
	int *paux = &aux;

	head = NULL;
	while (p < *pos - 1)
	{
		sp = 0;
		flag = 1;
		n = crear_name(name);
		while (buf[p] == ' ' || buf[p] == '\t')
			p++, aux++;
		while (p <= *pos)
		{
			if (p == *pos && buf[p] != ' ' && buf[p] != '\t'
			    && !istoken(buf[p]))
				sp++;
			if (buf[p] == ' ' || istoken(buf[p]) || buf[p] == '\t')
			{
				if (flag)
					sp++;
				flag = 0; }
			else
				flag = 1;
			if (istoken(buf[p]))
				break;
			p++; }
		if (p != 0 && sp == 0)
			sp++;
		p++;
		while (buf[p] == ' ' || buf[p] == '\t')
			p++;
		args = fill_nodes(buf, sp, pos, paux);
		id = clfun(&args[0]);
		add_node(&head, args, id, 0, n); }
	return (head);
}

/**
 * fill_nodes - create a linked list that contains all arguments.
 * @buf: poiter to pointer to a space in memory
 * @sp: number of args of a token
 * @pos: size of the all line (all commands)
 * @paux: actual position y the all line (all commands)
 * Return: a pointer to the linked list
 */
char **fill_nodes(char *buf, int sp, ssize_t *pos, int *paux)
{
	char **args = NULL;
	int aux2 = 0, s = 0, y = 0, j = 0, x = 0, aux3 = 0;

	s = 0;
	aux3 = *paux;
	args = malloc(sizeof(char *) * (sp + 1));
	if (!args)
		return (NULL);
	*(args + sp) = NULL;
	for (x = 0; sp > 0; sp--, x++)
	{
		aux2 = aux3;
		for (s = 0; buf[aux3] != ' ' && buf[aux3] != '\t'
			     && !istoken(buf[aux3])
			     && aux3 <= *pos; aux3++, s++)
			;
		args[x] = malloc(sizeof(char) * (s + 1));
		if (!args[x])
		{
			for (y = 0; y < x; y++)
				free(args[y]);
			free(args);
			return (NULL);
		}
		for (j = 0; j < s; j++, aux2++)
			*(*(args + x) + j) = buf[aux2];
		*(*(args + x) + s) = 0;
		while (buf[aux3] && (buf[aux3] == ' ' || istoken(buf[aux3]) ||
				     buf[aux3] == '\t'))
			aux3++;
	}
	*paux = aux3;

	return (args);
}
