#include "main.h"

/**
 * _realloc - Function that helps reallocate memory block.
 * @ptr: A pointer to the memory previously allocated.
 * @size: buffer holding the size,space of ptr
 * @val_byte: buffer holding the new size of the memory block
 * Return: realloc ptr
 * if malloc fails, return NULL.
 */

void *_realloc(void *ptr, unsigned int size, unsigned int val_byte)
{
	void *is_ptr;

	if (ptr == NULL)
		return (malloc(val_byte));

	if (val_byte == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (val_byte == size)
		return (ptr);

	is_ptr = malloc(val_byte);
	if (is_ptr == NULL)
		return (NULL);
	if (val_byte < size)
		_memcpy(is_ptr, ptr, val_byte);
	else
		_memcpy(is_ptr, ptr, val_byte);
	free(ptr);
	return (is_ptr);
}

/**
 * _memcpy - Fun that  helps copies info between void pointers.
 * @newptr: A pointer to the destination buffer pointer
 * @ptr: A pointer to the source buffer holding the pointer to copy
 * @byte_size: size of the new pointer.
 * Return: no return.
 */

void _memcpy(void *newptr, const void *ptr, unsigned int byte_size)
{
	unsigned int x;
	char *charNewptr = (char *)newptr;
	char *charPtr = (char *)ptr;

	while (x < byte_size)
	{
		charNewptr[x] = charPtr[x];
		x++;
	}
}

/**
 * _reallocptr - function that helps reallocate memory bock of a double pointer
 * @ptr: A double pointer pointing to the memory previosly allocated.
 * @size: size of bytes of allocated space of pointer
 * @value_byte: Buffer holding the new byte/value of a new memory block
 * Return: pointer
 * if size is equal to value_byte return ptr with no changes
 * if malloc fails, return (NULL).
 */

char **_reallocptr(char **ptr, unsigned int size, unsigned int value_byte)
{
	unsigned int x;
	char **newPtr;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * value_byte));
	if (value_byte == size)
		return (ptr);

	newPtr = malloc(sizeof(char *) * value_byte);
	if (newPtr == NULL)
		return (NULL);
	x = 0;

	while (x < size)
	{
		newPtr[x] = ptr[x];
		x++;
	}
	free(ptr);
	return (newPtr);
}
