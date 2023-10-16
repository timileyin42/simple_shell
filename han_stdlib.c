#include "holberton.h"

/**
 * _realloc - This fuction creates an array of integers.
 * @ptr: pointer that points to the data that will be reallocated.
 * @old_size: size of ptr
 * @new_size: new size of ptr
 * Return: pointer to the new adress of data.
 *
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *array = NULL;
	char *p = NULL;
	unsigned int x;
	char *px = NULL;

	if (ptr == NULL)
	{
		array = malloc(new_size);
		if (array == NULL)
			return (NULL);
		return (array);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size ==  old_size)
		return (ptr);
	p = malloc(new_size);
	if (p != NULL)
	{
		px = (char *)ptr;
		for (; x < old_size; x++)
			p[x] = px[x];
		free(ptr);
		return (p);
	}
	return (NULL);
}

#include <stdlib.h>
#include "holberton.h"

/**
 * _calloc - This fuction allocates memory using malloc
 * @nmemb: number of elements.
 * @size: size in bytes of each element.
 * Return: pointer to the espace reserved.
 *
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *array = NULL;
	unsigned int x;
	unsigned int t;
	char *f;

	if (size == 0 || nmemb == 0)
		return (NULL);
	t = nmemb * size;
	array = malloc(t);
	f = (char *)array;
	if (f != NULL)
	{
		for (; x < t; x++)
			f[x] = 0;
		return (f);
	}
	return (NULL);
}
