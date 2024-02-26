#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * get_new_size - calculates the new size for the buffer
 * @oldsize: the old size of the buffer
 * Return: the new size of the buffer
 */
size_t get_new_size(size_t oldsize)
{
	size_t newsize;

	newsize = oldsize + (oldsize >> 2);
	if (newsize < 120)
	{
		newsize = 120;
	}

	return (newsize);
}

/**
 * realloc_buffer - reallocates the buffer to a new size
 * @buff: the old buffer
 * @newsize: the new size of the buffer
 * Return: a pointer to the newly allocated buffer or NULL on failure
 */
char *realloc_buffer(char *buff, size_t newsize)
{
	char *newptr;

	newptr = realloc(buff, newsize);
	if (newptr == NULL)
	{
		return (NULL);
	}

	return (newptr);
}

/**
 * _getline - gets line from std
 * @line_str: ptr to line str
 * @nd: n val
 * @st_ream: ptr to file stream
 * Return: retuns str
 */
ssize_t _getline(char **line_str, size_t *nd, FILE *st_ream)
{
	size_t id;
	char a, *newptr;
	size_t newsize;

	if (!line_str || !nd || !st_ream)
	{
		errno = EINVAL;
		return (-1);
	}
	if (*line_str == NULL || *nd == 0)
	{
		*nd = 120;
		*line_str = (char *)malloc(*nd);
		if (*line_str == NULL)
		{
			return (-1);
		}
	}
	id = 0;
	while (fread(&a, sizeof(char), 1, st_ream) == 1)
	{
		if (id + 1 >= *nd)
		{
			newsize = get_new_size(*nd);
			newptr = realloc_buffer(*line_str, newsize);
			if (newptr == NULL)
			{
				return (-1);
			}
			*nd = newsize;
			*line_str = newptr;
		}
		(*line_str)[id++] = a;
		if (a == '\n')
		break;
	}
	(*line_str)[id] = '\0';
	return (id > 0 ? (ssize_t)id : -1);
}
