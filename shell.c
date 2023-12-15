#include "shell.h"

/**
 * main - entry fun
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *input;

	if (argc == 1 || isatty(STDIN_FILENO))
	{

	while (1)
	{
		display_prompt();

		input = my_getline();

		if (input == NULL)
		{
			_putchar("\n");
			free(input);
			break;
		}
		if (*input != '\0')
		{
			execute_command(input);
		}
		free (input);
	}
	}
	else if (argc == 2)
	{
		FILE *input_file;
		size_t len;
		ssize_t read;
		char *line;
			
		input_file = fopen(argv[1], "r");

		if (input_file == NULL)
		{
			perror("Error opening input file");
			exit(EXIT_FAILURE);
		}
			
		line = NULL;
		len = 0;

		while ((read = getline(&line, &len, input_file)) != -1)
		{
			line[strcspn(line, "\n")] = '\0';

			execute_command(line);
		}

		fclose(input_file);
		free(line);
	}
	return (0);
}
