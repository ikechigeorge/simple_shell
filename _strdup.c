#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string
 * @string: pointer to the string
 *
 * Return: return address to string
 */
char *_strdup(const char *string)
{
	char *ab = malloc(_strlen(string) + 1);

	if (ab != NULL)
	{
		_strcpy(ab, string);
	}

	return (ab);
}
