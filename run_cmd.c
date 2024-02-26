#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * run_cmd - runs command
 * @shelldata: shell data
 *
 * Return: void
 */
void run_cmd(info_t *shelldata)
{
	void (*exec_command)(info_t *) = select_cmd(shelldata->line);

	exec_command(shelldata);
}
