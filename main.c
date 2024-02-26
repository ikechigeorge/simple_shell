#include "main.h"
#include <stdio.h>

/**
 * main - Entry point for shell
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, -1 on failure
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	ssize_t rd;
	size_t length = 0;
	info_t shelldata = {
		NULL, 1, "\0", 0
	};

	_strcpy(shelldata.shell_name, argv[0]);
	if (!isatty(STDIN_FILENO))
	{
		shelldata.interactive = 0;
	}
		prompt(&shelldata);
	while ((rd = _getline(&shelldata.line, &length, stdin)) != -1)
	{
		if (shelldata.line[0] == '\n')
		{
			prompt(&shelldata);
			continue;
		}
		if (shelldata.line[rd - 1] == '\n')
			shelldata.line[rd - 1] = '\0';

		run_cmd(&shelldata);
		prompt(&shelldata);
	}
	free_multiple(1, shelldata.line);
	return (0);
}
