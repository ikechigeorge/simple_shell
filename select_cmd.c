#include "main.h"

/**
 * select_cmd - selects function to run for a command
 * @_cmd: command to check
 * Return: pointer to function
 */
void (*select_cmd(char *_cmd))(info_t *)
{
	int j = 0;
	char *copycmd = _strdup(_cmd);
	char *tok;
	command_t __commands[] = {
		{"exit", __exit},
		{"env", _env},
		{NULL, NULL}
	};

	tok = _strtok(copycmd, " ");
	while (1 && tok != NULL)
	{
		if (__commands[j].command == NULL)
			break;
		if (_strcmp(tok, __commands[j].command) != 0)
		{
			j++;
			continue;
		}
		free_multiple(1, copycmd);
		return (__commands[j].f);
	}
	free_multiple(1, copycmd);
	return (_exec);
}
