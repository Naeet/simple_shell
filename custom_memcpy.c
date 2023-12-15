#include "shell.h"

/**
 * _memcpy - copy  memory with constant byte
 * @dest: destn
 * @src: source
 * @n: byte
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i;
	int r = n;

	for (i = 0; i < r; i++)
	{
		dest[i] = src[i];
		n--;
	}
	return (dest);
}
