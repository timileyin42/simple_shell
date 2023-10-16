#include "holberton.h"

/**
 * _have_value - Functions that helps find the valueof alias.
 * @arg: pointer to arg
 *
 * Return: 0 or-1
 */
int _have_value(char *arg)
{
	int x = 0;

	if (arg)
	{
		for (; arg[x]; x++)
			if (arg[x] == '=')
				return (1);
		return (0);
	}
	return (-1);
}

/**
 * _quote_end - show help document of some functions.
 * @s1: node tha has the builtin command
 *
 * Return: no return
 */
int _quote_end(char *s1)
{
	int x = 0;

	for (; s1[x]; x++)
		if (s1[x] == 39 && !s1[x + 1])
			return (1);
	return (0);
}

/**
 * token_alias - show help document of some functions.
 * @alias: node tha has the builtin command
 *
 * Return: no return
 */
char **token_alias(char *alias)
{
	char **tokens = NULL;
	int x = 0, pos = 0, y = 0, lv = 0;

	tokens = _calloc(2, sizeof(char *));
	for (; alias[pos]; pos++)
		if (alias[pos] == '=')
			break;
	if (pos == 0)
	{
		return (NULL);
	}
	l = _strlen(alias);
	lv = y - 2 - pos;
	tokens[0] =  _calloc(pos + 1, sizeof(char));
	tokens[1] = _calloc(lv + 1, sizeof(char));
	for (; x < pos; x++)
		tokens[0][x] = alias[x];
	pos++;
	for (; x < lv; x++)
		tokens[1][x] = alias[pos + x];
	return (tokens);
}

/**
 * _concat - show help document of some functions.
 * @args: node tha has the builtin command
 * @pos: position
 * @size: size
 * Return: no return
 */
char *_concat(char **args, int *pos, int size)
{
	char *aux = NULL;
	int cnt = 0, x = 0, tot = 0, y = 0, z = 0;

	cnt  = *pos + 1;
	while (cnt <= size && !_quote_end(args[cnt]))
		cnt++;
	if (!_quote_end(args[cnt]))
		return (NULL);
	for (x = *pos; x <= cnt; x++)
		tot = tot + _strlen(args[x]);
	aux = _calloc(tot, sizeof(char));
	for (x = *pos; x <= cnt; x++)
	{
		for (; args[x][y]; x++, z++)
			aux[z] = args[x][y];
		aux[z] = ' ';
		z++;
	}
	z--;
	aux[z] = 0;
	*pos = cnt + 1;
	return (aux);
}

/**
 * print_one_alias - show help document of some functions.
 * @name: node tha has the builtin command
 *
 * Return: no return
 */
int print_one_alias(char *name)
{
	alias *aux = NULL;
	char *err = "alias: ";
	char *err1 = " not found\n";
	char eq = '=', sl = 10, qu = 39;

	aux = setalias(NULL);
	aux = buscar_alias(aux, name);
	if (aux)
	{
		write(STDOUT_FILENO, aux->name, _strlen(aux->name) - 1);
		write(STDOUT_FILENO, &eq, 1);
		write(STDOUT_FILENO, &qu, 1);
		write(STDOUT_FILENO, aux->value, _strlen(aux->value) - 1);
		write(STDOUT_FILENO, &qu, 1);
		write(STDOUT_FILENO, &sl, 1);
		return (0);
	}
	write(STDOUT_FILENO, err, _strlen(err));
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, err1, _strlen(err1));
	return (-1);
}
