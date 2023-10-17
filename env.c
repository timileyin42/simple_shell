#include "holberton.h"
#include <stdio.h>
#define LIM 1024
/**
 * _readandcpy - function that reads from fr and copy to to
 * @fr: file origin.
 * @to: file destiny.
 * @buf: buffer to store the characters.
 * Return: nothing.
 */
int _readandcpy(char *fr, char *to, char *buf)
{
	int f, t, n_read = LIM, n_write, x, y, total = 0;

	if (!fr)
	{
error98:
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", fr);
		exit(98);
	}
	f = open(fr, O_RDONLY, 0400);
	t = open(to, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0777);

	if (f == -1)
		goto error98;
	if (t == -1)
	{
error99:
		dprintf(2, "Error: Can't write to %s\n", to);
		exit(99);
	}
	while (n_read == LIM)
	{
		n_read = read(f, buf, LIM);
		if (n_read == -1)
			goto error98;
		total = total + n_read;
		n_write = write(t, buf, n_read);
		if (n_write != n_read)
			goto error99;
	}
	x = close(f);
	y = close(t);
	if (x == -1 || y == -1)
	{
		if (x == -1)
			dprintf(2, "Error: Can't close fd %d\n", f);
		if (y == -1)
			dprintf(2, "Error: Can't close fd %d\n", t);
		exit(100);
	}
	return (total);
}
