#include "main.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

/**
 * print_exit_error - prints error message for exit command
 * @data: shell data information
 * @ptr: program exit code
 * Return: void
 */
void print_exit_error(info_t *data, char *ptr)
{
	dprintf(STDERR_FILENO, "%s: 1: exit: Illegal number: %s\n",
	data->shell_name, ptr);
}

/**
 * __exit - exit from shell
 * @data: shell data
 * Return: void
 */
void __exit(info_t *data)
{
	char *val;
	char *stringcopy = NULL;
	int exitcode = data->exit_code;

	stringcopy = _strdup(data->line);
	val = _strtok(stringcopy, " ");
	val = _strtok(NULL, " ");
	if (val != NULL)
	{
		exitcode = _atoi(val);
		if (is_valid_number(val) == 0)
		{
			print_exit_error(data, val);
			free_multiple(1, stringcopy);
			if (data->interactive == 1)
				return;
			free_multiple(1, data->line);
			exit(2);
		}
		if (exitcode < 0)
		{
			print_exit_error(data, val);
			free_multiple(2, data->line, stringcopy);
			exit(2);
		}
	}
	free_multiple(2, data->line, stringcopy);
	exit(exitcode);
}
