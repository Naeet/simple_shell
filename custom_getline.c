#include "shell.h"

/**
 * my_getline - custom getline
 * Return: line
 */
char *my_getline(void)
{
	char buffer[READ_SIZE], *line = NULL, *newline_pos, *temp;
	size_t buffer_index = 0, line_size = 0, copy_chars;

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
			buffer_index = (size_t)read_chars;
		}
		newline_pos = _memchr(buffer, '\n', buffer_index);
		copy_chars = (newline_pos != NULL)
			? (size_t)(newline_pos - buffer + 1) : buffer_index;

		temp = _realloc(line, line_size + copy_chars);
		if (temp == NULL)
		{
			perror("realloc error");
			exit(EXIT_FAILURE);
		}
		line = temp;
		_memcpy(line + line_size, buffer, copy_chars);
		buffer_index -= copy_chars;
		line_size += copy_chars;
		if (newline_pos != NULL)
			break;
	}
	line[line_size] = '\0';
	return (line);
}
