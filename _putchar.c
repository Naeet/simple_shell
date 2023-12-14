#include "shell.h"
/**
 * _putchar - printf
 * @string: to be prined
 */
void _putchar(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
