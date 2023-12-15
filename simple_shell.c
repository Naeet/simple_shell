#include "shell.h"

/**
 * main - e
 * Return: res
 */
int main(void)
{
	char *input;

	while (1)
	{
		display_prompt();

		input = read_input();

		if (!input)
		{
			free(input);
			break;
		}

		execute_command(input);

		free(input);

	}

	return (0);
}
