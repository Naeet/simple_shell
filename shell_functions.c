#include "shell.h"
/**
 * display_prompt - f
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("nae$ ");
		fflush(stdout);
	}
}
/**
 * read_input - f
 * Return: input
 */
char *read_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;


	if (getline(&input, &bufsize, stdin) == -1)
	{
		free(input);
		return (NULL);
	}

	return (input);
}
