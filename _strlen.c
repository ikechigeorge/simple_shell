#include "main.h"

/**
 * _strlen - count the length of a string
 * @string: the string to count
 * Return: the length of the string
 */
int _strlen(const char *string)
{
	int j;

	j = 0;
	while (*(string + j) != '\0')
	{
		j++;
	}

	return (j);
}
