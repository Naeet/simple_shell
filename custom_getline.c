#include "shell.h"
#define READ_SIZE 1024
/**
 * _getline - cust
 * Return: line
 */
char *_getline(void)
{
	static char buffer[READ_SIZE], *line = NULL;
	static size_t buffer_index, line_size = 0;
		
	buffer_index = 0;
	while (1)
	{
		if (buffer_index == 0)
		{
			ssize_t read_chars = read(STDIN_FILENO, buffer, sizeof(buffer));

			if (read_chars == 0)
			{
				if (line_size == 0)
					return (NULL);
				break;
			}

			if (read_chars == -1)
			{
				perror("read error");
				exit(EXIT_FAILURE);
			}
			buffer_index = read_chars;
		}

		char *newline_pos = memchr(buffer, '\n', buffer_index);
		size_t copy_chars = (newline_pos != NULL)
		       ? (size_t)(newline_pos - buffer + 1) : buffer_index;

		line = realloc(line, line_size + copy_chars);

		if (line == NULL)
		{
			perror("realloc error");
			exit(EXIT_FAILURE);
		}

		memcpy(line + line_size, buffer, copy_chars);

		buffer_index -= copy_chars;
		line_size += copy_chars;

		if (newline_pos != NULL)
			break;
	}
	line[line_size] = '\0';

	return (line);
}
