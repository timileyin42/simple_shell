#include "shell.h"

/**
 * _have_value - valueof alias.
 * @arg: pointer to arg
 *
 * Return: 0 or-1
 */
int _have_value(char *arg)
{
	int i = 0;

	if (arg)
	{
		for (; arg[i]; i++)
			if (arg[i] == '=')
				return (1);
		return (0);
	}
	return (-1);
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
	int i = 0, pos = 0, l = 0, lv = 0;

	tokens = _calloc(2, sizeof(char *));
	for (; alias[pos]; pos++)
		if (alias[pos] == '=')
			break;
	if (pos == 0)
	{
		return (NULL);
	}
	l = _strlen(alias);
	lv = l - 2 - pos;
	tokens[0] =  _calloc(pos + 1, sizeof(char));
	tokens[1] = _calloc(lv + 1, sizeof(char));
	for (i = 0; i < pos; i++)
		tokens[0][i] = alias[i];
	pos++;
	for (i = 0; i < lv; i++)
		tokens[1][i] = alias[pos + i];
	return (tokens);
}

/**
 * _quote_end - show help document of some functions.
 * @s1: node tha has the builtin command
 *
 * Return: no return
 */
int _quote_end(char *s1)
{
	int i = 0;

	for (; s1[i]; i++)
		if (s1[i] == 39 && !s1[i + 1])
			return (1);
	return (0);
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
	int cnt = 0, i = 0, tot = 0, j = 0, g = 0;

	cnt  = *pos + 1;
	while (cnt <= size && !_quote_end(args[cnt]))
		cnt++;
	if (!_quote_end(args[cnt]))
		return (NULL);
	for (i = *pos; i <= cnt; i++)
		tot += _strlen(args[i]);
	aux = _calloc(tot, sizeof(char));
	for (i = *pos; i <= cnt; i++)
	{
		for (j = 0; args[i][j]; j++, g++)
			aux[g] = args[i][j];
		aux[g] = ' ';
		g++;
	}
	g--;
	aux[g] = 0;
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
		write(1, aux->name, _strlen(aux->name) - 1);
		write(1, &eq, 1);
		write(1, &qu, 1);
		write(1, aux->value, _strlen(aux->value) - 1);
		write(1, &qu, 1);
		write(1, &sl, 1);
		return (0);
	}
	write(1, err, _strlen(err));
	write(1, name, _strlen(name));
	write(1, err1, _strlen(err1));
	return (-1);
}
