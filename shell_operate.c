#include "holberton.h"

/**
 * _ignorecomments - function that help to ignore ignorecomments.
 * @buf: node tha has the builtin command
 * @d: integer
 * Return: no return
 */
void _ignorecomments(char *buf, int *d)
{
	while (buf[*d] != 0 && buf[*d] != '\n')
	{
		*d = *d + 1;
	}
	*d = *d + 1;
}

/**
 * _replacealias - show help document of some functions.
 * @ali: node tha has the builtin command
 * @newbuf: new buffer
 * @pos: size all line
 *
 * Return: no return
 */
void _replacealias(alias *ali, char *newbuf, int *pos)
{
	int x = 0;
	char *value = NULL;
	alias *aux = NULL;

	aux = setalias(NULL);
	aux = buscar_alias(aux, ali->value);
	if (aux)
		ali = aux;
	value = ali->value;
	while (value[x])
	{
		if (value[x] != 39)
		{
			newbuf[*pos] = value[x];
			*pos = *pos + 1;
		}
		x++;
	}
}

/**
 * _isalias - show help document of some functions.
 * @buf: node tha has the builtin command
 * @d: integer
 *
 * Return: no return
 */
alias *_isalias(char *buf, int *d)
{
	alias *ali =  NULL;
	int x = *d, y = 0;
	char *name = NULL;

	if (x != 0 && !_isespecialchr(buf[(x - 1)]))
		return (NULL);
	name = _calloc(500, 1);
	for (; !_isespecialchr(buf[x]); x++)
		;
	for (; (y + *d) < x; y++)
		name[y] = buf[y + *d];
	ali = setalias(NULL);
	ali = buscar_alias(ali, name);
	free(name);
	if (ali)
	{
		*d = x;
		return (ali);
	}
	return (NULL);
}

/**
 * buffer_filter - show help document of some functions.
 * @buffer: node tha has the builtin command
 * @p: p
 *
 * Return: no return
 */
void buffer_filter(char **buffer, ssize_t *p)
{
	char *newbuf = _calloc(4096 * 2, 1);
	alias *ali = NULL;
	char *buf = *buffer;
	int pos = 0, x = 0, cpy = 0;

	while (x <= *p)
	{
		if (buf[x] == '#')
		{
			if (x == 0)
			{
				_ignorecomments(buf, &x);
				continue; }
			else if (buf[x - 1] == ' ' || buf[x - 1] == '\t' ||
				 buf[x - 1] == ';')
			{
				_ignorecomments(buf, &x);
				continue; }
		}
		if (buf[x] == '$' && buf[x + 1] != ' ' && buf[x + 1] != '\t'
			    && buf[x + 1] != 0 && buf[x + 1] != '\n'
		    && buf[x + 1] != ';')
		{
			_replacevar(buf, newbuf, &x, &pos);
			continue; }
		cpy = x;
		ali = _isalias(buf, &x);
		if (ali)
		{
			if (!have_alias(buf, x))
			{
				_replacealias(ali, newbuf, &pos);
				continue; }
			x = cpy; }
		x = cpy;
		newbuf[pos] = buf[x];
		x++, pos++; }
	free(buf);
	*p = pos;
	*buffer = newbuf;
}
