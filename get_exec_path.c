#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * get_exec_path - get path
 * @prog: program name to find the executable
 * Return: fullpath to executable on Success,
 * NULL on failure
 */
char *get_exec_path(char *prog)
{
	char *pathfind = _getenv("PATH");
	char *copypath = NULL, *tok;
	char full_path[PATH_MAX];

	if (pathfind == NULL)
		return (NULL);
	copypath = _strdup(pathfind);
	tok = _strtok(copypath, ":");
	while (tok != NULL)
	{
		_strcpy(full_path, tok);
		if (full_path[_strlen(full_path) - 1] != '/')
		{
			strcat(full_path, "/");
		}
		_strcat(full_path, prog);
		if (access(full_path, F_OK) == 0)
		{
			free_multiple(1, copypath);
			return (_strdup(full_path));
		}
		tok = _strtok(NULL, ":");
	}
	free_multiple(1, copypath);
	if (access(prog, F_OK) == 0)
		return (_strdup(prog));
	return (NULL);
}
