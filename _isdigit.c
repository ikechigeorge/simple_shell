#include "main.h"

/**
 * _isdigit - checks if a number is a digit
 * @ab: number to check
 * Return: 1 if digit, else 0
 */
int _isdigit(int ab)
{
	if (ab >= 48 && ab <= 57)
	{
		return (1);
	}

	return (0);
}

/**
 * is_valid_number - checks if a number is a valid number
 * @string: string to check
 * Return: 1 if valid, else 0
 */
int is_valid_number(const char *string)
{
	if (*string == '\0')
	{
		return (0);
	}
	if (*string == '+' || *string == '-')
	{
		string++;
	}

	while (*string != '\0')
	{
		if (!_isdigit(*string))
		{
			return (0);
		}
		string++;
	}

	return (1);
}
