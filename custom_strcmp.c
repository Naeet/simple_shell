#include "shell.h"
/**
 * _strcmp - concatenate
 * @s1: string 1
 * @s2: str 2
 * Return: int of cmp
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0 ; s1[i] != '\0' || s2[i] != '\0' ; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
