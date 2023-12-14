#include "shell.h"
/**
 * _strcpy - custom strcpy
 * @dest: par
 * @src: par
 *
 * Return: to des
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0 ; src[i] != ('\0') ; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}
