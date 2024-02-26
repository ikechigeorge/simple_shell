#include "main.h"
#include <unistd.h>
#include <string.h>

/**
 * _getenv - get an environmental variable
 * @var: variable to find
 * Return: variable if found, else NULL
 */
char *_getenv(char *var)
{
	int j = 0;
	size_t length = _strlen(var);

	while (environ[j] != NULL)
	{
		if (_strncmp(environ[j], var, length) == 0 && environ[j][length] == '=')
		{
			return (&environ[j][length + 1]);
		}
		j++;
	}
	return (NULL);
}
