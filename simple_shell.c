#include "shell.h"

/**
 * main - e
 * @argc: a
 * @argv: v
 * Return: res
 */
/**
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		interactive_mode();
	}
	else if (argc == 2)
	{
		non_interactive_mode(argv[1]);
	}
	else
	{
		fprintf(stderr, "Usage: %s [script]\n", argv[0]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}**/

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
