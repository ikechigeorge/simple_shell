#include "main.h"

/**
 * _strcat - concatinating string
 * @cont: where to contacatinate the string
 * @string: wehere to get the string
 * Return: pointer to @dest
 */
char *_strcat(char *cont, char *string)
{
	int adida = 0;
	int zod = 0;

	while (cont[adida] != '\0')
	{
		adida++;
	}
	while (string[zod] != '\0')
	{
		cont[adida] = string[zod];
		adida++;
		zod++;
	}
	cont[adida] = '\0';
	return (cont);
}
