#include "main.h"

/**
 * _strcpy - copies src to deat
 * @cont: destination of string
 * @string: source of string
 *
 * Return: returns pointer to the dest.
 */
char *_strcpy(char *cont, const char *string)
{
	char *temp = cont;

	while (*string != '\0')
	{
		*cont = *string;
		cont++;
		string++;
	}
	*cont = '\0';

	return (temp);
}
