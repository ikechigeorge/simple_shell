#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * count_array_size - count the size of an array
 * @array: the array to count
 * Return: The size of the array
 */
int count_array_size(char **array)
{
	int j = 0;

	while (array[j] != NULL)
	{
		j++;
	}
	return (j);
}

/**
 * invalid_argv - checks if an argument is invalid
 * @arg: the arguments to check
 * @data: the shell data
 * Return: -1 if the argument is invalid
 * and 0 otherwise
 */
int invalid_argv(char **arg, info_t *data)
{
	if (arg[0] == NULL || arg[0][0] == '\0')
	{
		free_array((void **)arg, count_array_size(arg));
		if (data->interactive == 0)
		{
			free_multiple(1, data->line);
			exit(EXIT_SUCCESS);
		}
		else
		return (-1);
	}
	else
	return (0);
}

/**
 * hangle_path_null - checks if the path is invalid
 * @path: path to check
 * @arg: list of arguments
 * @data: the shell data
 * Return: void
 */
void hangle_path_null(char *path, char **arg, info_t *data)
{
	dprintf(STDERR_FILENO, "%s: 1: %s: not found\n",
	data->shell_name, arg[0]);
	free_array((void **)arg, count_array_size(arg));
	if (data->interactive == 0)
	{
		free_multiple(2, path, data->line);
		exit(127);
	}
}

/**
 * _exec - execute a program
 * @data: shell data
 * Return: void
 */
void _exec(info_t *data)
{
	char *path = NULL;
	char **arg = NULL;
	pid_t child;
	int status;

	arg = get_argv(data->line);
	if (invalid_argv(arg, data) == -1)
		return;
	else if (arg[0][0] != '/' && arg[0][0] != '.')
		path = get_exec_path(arg[0]);
	else
		path = _strdup(arg[0]);
	if (path == NULL)
		hangle_path_null(path, arg, data);
	else
	{
		child = _fork();
		if (child == 0)
		{
			if (execve(path, arg, environ) == -1)
			{
				perror(data->shell_name);
				exit(EXIT_FAILURE);
			}
		}
		wait(&status);
		data->exit_code = WEXITSTATUS(status);
		free_array((void **)arg, count_array_size(arg));
		free_multiple(1, path);
		if (data->interactive == 0)
		{
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			{
				free_multiple(1, data->line);
				exit(2);
			}
		}
	}
}
