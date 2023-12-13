#include "shell.h"

/**
 * main - entry fun
 * Return: 0
 */

int main(void)
{
	char *input;

	while (1)
	{
		display_prompt();

		input = my_getline();

		if (input == NULL)
		{
			printf("\n");
			break;
		}
		if (*input != '\0')
		{
			execute_command(input);
		}
		free(input);
	}
	return (0);
}
