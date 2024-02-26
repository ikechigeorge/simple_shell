#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _env - print all environment variables
 * @shell: shell data
 * Return: void
 */
void _env(info_t *shell)
{
	int j = 0;

	UNUSED(shell);

	while (environ[j] != NULL)
	{
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
}
