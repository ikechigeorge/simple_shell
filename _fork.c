#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * _fork - wrapper function for fork
 * Return: child process identifier
 */
pid_t _fork(void)
{
	pid_t id = fork();

	if (id == -1)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	}

	return (id);
}
