#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * free_multiple - free multiple memory
 * @mem: number of memory to free
 * Return: Void
 */
void free_multiple(int mem, ...)
{
	int j;
	void *str;
	va_list argb;

	va_start(argb, mem);
	for (j = 0; j < mem; j++)
	{
		str = va_arg(argb, void *);
		if (str != NULL)
		{
			free(str);
			str = NULL;
		}
	}
	va_end(argb);
}

/**
 * free_array - free multiple memory array
 * @arr: array to free
 * @arraysize: size of array to free
 * Return: Void
 */
void free_array(void **arr, int arraysize)
{
	int j;

	for (j = 0; j < arraysize; j++)
	{
		free_multiple(1, arr[j]);
	}
	free_multiple(1, arr);
}

/**
 * _malloc - a wrapper for malloc
 * @_memsize: size of memory to allocate
 * Return: pointer to allocated memory
 */
void *_malloc(size_t _memsize)
{
	void *str = malloc(_memsize);

	if (str == NULL)
	{
		exit(EXIT_FAILURE);
	}
	return (str);
}

/**
 * _realloc - a wrapper for realloc
 * @str: pointer to the function to resize
 * @_memsize: size of new memory size
 * Return: void
 */
void *_realloc(void *str, size_t _memsize)
{
	str = realloc(str, _memsize);

	if (str == NULL)
	{
		exit(EXIT_FAILURE);
	}
	return (str);
}
