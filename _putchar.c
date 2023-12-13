#include "shell.h"
/**
 * _putchar - printf 
 * @string: to be prined
 * @descriptor: int
 */
void _putchar(const char *string)
{
/*
	for (; string[i] != '\0'; i++)
		write(STDOUT_FILENO, &string[i], 1);
*/
	write(STDOUT_FILENO, string, strlen(string));
}
