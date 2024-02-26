#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * realloc_array - reallocates an array memory
 * @realoc: array to reallocate
 * @arraysize: size of the array
 * @argc: for freeing array
 * @strcopy: string to free if failed
 * Return: pointer to reallocates memory
 */
void **realloc_array(void **realoc, int *arraysize, int *argc, char *strcopy)
{
	(*arraysize) *= 2;
	realoc = realloc(realoc, (*arraysize) * sizeof(char *));
	if (realoc == NULL)
	{
		free_array(realoc, *argc);
		free_multiple(1, strcopy);
		exit(EXIT_FAILURE);
	}
	return (realoc);
}

/**
 * get_argv - sets argument vector for program
 * @string: string containing argument
 * Return: array containing string of argument
 */
char **get_argv(char *string)
{
	char **zod = NULL;
	int argb = 0;
	int arrsize = 10;
	char *tok;
	char *strcopy;

	strcopy = _strdup(string);
	zod = _malloc(arrsize * sizeof(char *));
	tok = _strtok(strcopy, " ");
	while (tok != NULL)
	{
		if (argb >= arrsize)
		zod = (char **)realloc_array((void **)zod, &arrsize, &argb, strcopy);
		zod[argb] = _strdup(tok);
		if (zod[argb] == NULL)
		{
			free_array((void **)zod, argb);
			free_multiple(1, strcopy);
			exit(EXIT_FAILURE);
		}
		argb++;
		tok = _strtok(NULL, " ");
	}
	if (argb >= arrsize)
	{
		zod = (char **)realloc_array((void **)zod, &arrsize, &argb, strcopy);
		zod[argb] = NULL;
		free_multiple(1, strcopy);
	}
	return (zod);
}
