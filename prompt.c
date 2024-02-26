#include "main.h"

/**
 * prompt - Prints prompt message
 * @shelldata: shell data information
 * Return: void
 */
void prompt(info_t *shelldata)
{
	if (shelldata->interactive == 1)
	{
		write(STDOUT_FILENO, PROMPT_MSG, PROMPT_LEN);
	}
}
