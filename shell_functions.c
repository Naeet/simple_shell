#include "shell.h"

void interactive_mode(void)
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
}
void non_interactive_mode(char *script_path)
{
	FILE *script = fopen(script_path, "r");
	char *input = NULL;
	size_t len = 0;

	if (!script)
	{
		perror("Error opening script");
		exit(EXIT_FAILURE);
	}

	while (getline(&input, &len, script) != -1)
	{
		execute_command(input);
	}
	fclose(script);

	free(input);
}

void display_prompt(void)
{
	printf("nae$ ");
}
char *read_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;


	if (getline(&input, &bufsize, stdin) == -1)
	{
		free(input);
		return NULL;
	}

	return input;
}
