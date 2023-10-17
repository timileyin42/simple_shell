#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BSIZE 4
/**
 * _memset - fills memory with constant byte
 * @s: memory area
 * @b: constant byte b
 * @n: first n bytes of memory area pointed by s
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
/**
 * _memcpy - copies memory
 * @dest: destination
 * @src: source
 * @n: size of memory to copy
 *
 * Return: Returns memory copied
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to modify
 * @old_size: current size of memory
 * @new_size: size memory will now have
 *
 * Return: Pointer to reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *ptr2;

	if (old_size == new_size)
		return (ptr);

	if (ptr == NULL)
	{
		ptr2 = malloc(new_size);
		if (ptr2 == 0)
			return (0);
		free(ptr);
		return (ptr2);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (0);
	}

	ptr2 = malloc(new_size);

	if (ptr2 == 0)
		return (0);

	ptr2 = _memset(ptr2, '\0', new_size);

	_memcpy(ptr2, ptr, old_size);
	free(ptr);
	return (ptr2);
}
/**
 * _getline - read a string or a line from an input stream
 * @buffer: pointer to a space where the stdin read will be saved
 * as a string
 * @bufsize: current size of buffer (must be given as 0 initially)
 * @fd: stream to read
 *
 * Return: Number of Characters Read
 */
int _getline(char **buffer, size_t *bufsize, int fd)
{
	static char *buff;
	static size_t size;
	unsigned int len = 0, i = 0, sizeold;
	int r;

	if (*bufsize == 0)
		size = BSIZE;
	if (*buffer == 0)
	{
		buff = malloc(sizeof(char) * size);
		if (!buff)
			return (write(2, "Memory Error", 22), 0);
		*buffer = buff;
	}
	buff = _memset(buff, '\0', size);
	do {

		r = read(fd, buff + len, BSIZE);
		if (r >= 0)
			i = len, len += r;
		if (r == -1 || r == 0)
			return (-1);
		if  (len >= size)
		{
			sizeold = size, size += BSIZE;
			buff = _realloc(buff, sizeold, size);
			if (!buff)
				return (write(2, "Memory Error", 22), 0);
		}
		for (; i < len; i++)
		{
			if (buff[i] == '\n')
			{
				*buffer = buff, *bufsize = size;
				return (len);
			}
		}

	} while (1);
	return (len);
}
