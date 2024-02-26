#include "main.h"
#include <stdio.h>

/**
 * _strncmp - get difference of s1 && s2
 * @string1: string one
 * @string2:  string two
 * @num: number of char to compe.. up to
 * Return: returns difference btw s1 && s2 if eny else (0)
 */
int _strncmp(const char *string1, const char *string2, size_t num)
{
	size_t j;

	for (j = 0; j < num && string1[j] != '\0' && string2[j] != '\0'; j++)
	{
		if (string1[j] != string2[j])
		{
			return (string1[j] - string2[j]);
		}
	}
	if (j == num)
	{
		return (0);
	}
	else
	{
		return (string1[j] - string2[j]);
	}
}
