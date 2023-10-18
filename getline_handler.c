#include "main.h"

#define BSIZE 4

/**
 * _memset - fills memory with constant byte
 * @s: memory area
 * @c: constant byte b
 * @d: first n bytes of memory area pointed by s
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_memset(char *s, char c, unsigned int d)
{
	unsigned int x;

	while (x < d)
	{
		s[x] = c;
		x++;
	}
	return (s);
}
/**
 * _memcpy - Function that helps copies memory
 * @dest: destination
 * @src: source
 * @d: size of memory to copy
 *
 * Return: Returns memory copied
 */
char *_memcpy(char *dest, char *src, unsigned int d)
{
	unsigned int x = 0;

	while (x < d)
	{
		dest[x] = src[x];
		x++;
	}
	return (dest);
}

/**
 * _realloc - Function that reallocates a memory block using malloc and free
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
 * _getline - Function that read a string or a line from an input stream
 * @buffer: pointer to a space where the stdin read will be saved
 * as a string
 * @bufsize: current size of buffer (must be given as 0 initially)
 * @file_d: stream to read
 *
 * Return: Number of Characters Read
 */
int _getline(char **buffer, size_t *bufsize, int file_d)
{
	static char *buf;
	static size_t size;
	unsigned int len = 0, x = 0, size_of;
	int y;

	if (*bufsize == 0)
		size = BSIZE;
	if (*buffer == 0)
	{
		buf = malloc(sizeof(char) * size);
		if (buf == NULL)
			return (write(STDERR_FILENO, "Memory Error", 22), 0);
		*buffer = buf;
	}
	buf = _memset(buf, '\0', size);
	do {

		y = read(file_d, buf + len, BSIZE);
		if (y >= 0)
			x = len, len = len + y;
		if (y == -1 || y == 0)
			return (-1);
		if  (len >= size)
		{
			size_of = size, size = size + BSIZE;
			buf = _realloc(buf, size_of, size);
			if (buf == NULL)
				return (write(2, "Memory Error", 22), 0);
		}
		for (x = 0; x < len; x++)
		{
			if (buf[x] == '\n')
			{
				*buffer = buf, *bufsize = size;
				return (len);
			}
		}

	} while (1);
	return (len);
}
