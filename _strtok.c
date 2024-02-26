#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * _strtok - tokenizes a sentence
 * @string: sentence to tokenize
 * @chr: char to use for it
 * Return: returns string of each token
 */
char *_strtok(char *string, const char *chr)
{
	static char *nexttoken;

	if (string)
	{
		nexttoken = string;
	}

	if (!nexttoken)
	{
		return (NULL);
	}

	string = nexttoken + _strspn(nexttoken, chr);
	nexttoken = string + strcspn(string, chr);
	if (*nexttoken)
	{
		*nexttoken++ = '\0';
	}
	else
	{
		nexttoken = NULL;
	}
	return (*string ? string : NULL);
}
