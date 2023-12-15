#include "shell.h"
#include <unistd.h>
/**
 * _putchar - fun
 * @string: str
 */
void _putchar(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
