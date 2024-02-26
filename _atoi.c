#include "main.h"

/**
 * _atoi - converts string to number
 * @ptr: string to convert
 * Return: convert number
 */
int _atoi(char *ptr)
{
	int res = 0;
	int count = 1;
	int j = 0;

	while (ptr[j] != '\0' && (ptr[j] < '0' || ptr[j] > '9'))
	{
		if (ptr[j] == '-')
		{
			count *= -1;
		}
		j++;
	}
	while (ptr[j] != '\0' && ptr[j] >= '0' && ptr[j] <= '9')
	{
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && ptr[j] - '0' > 7))
		{
			if (count == 1)
			{
				return (INT_MAX);
			}
			else
			{
				return (INT_MIN);
			}
		}
		res = res * 10 + (ptr[j] - '0');
		j++;
	}
	return (res * count);
}
