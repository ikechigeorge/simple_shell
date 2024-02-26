#include "main.h"

/**
 * _strspn - calculates length of initial segment
 * of string that consists of characters in set
 * @string: the string
 * @acc: what to count in str
 * Return: retuns number of accept in str
 */
size_t _strspn(const char *string, const char *acc)
{
	size_t val = 0;
	int ptr = 0;
	const char *ab;

	while (*string)
	{
		ptr = 0;
		for (ab = acc; *ab; ab++)
		{
			if (*string == *ab)
			{
				ptr = 1;
				break;
			}
		}

		if (!ptr)
		{
			break;
		}

		val++;
		string++;
	}
	return (val);
}
