#include "main.h"

/**
 * _strcmp - compares two string
 * @str1: first string to compare
 * @str2: second string to compare
 * Return: integer
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
