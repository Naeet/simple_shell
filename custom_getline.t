#include "shell.h"
#define READ_SIZE 1024
/**
 * _getline - cust
 * Return: line
 */
char *_getline(void)
{
	static char buffer[READ_SIZE];
	static size_t buffer_index;
		
	buffer_index = 0;

	char *line = NULL;
	size_t line_size = 0;

	while (1)
	{
		read_input_g(buffer, &buffer_index);
		process_buffer(buffer, &buffer_index, &line, &line_size);
	}

	return (line);
}
/**
 * read_input_g - f
 * @buffer - buf
 * @buffer_index - indx
 */
void read_input_g(char buffer[], size_t *buffer_index)
{
	if (*buffer_index == 0)
	{
		ssize_t read_chars = read(STDIN_FILENO, buffer, sizeof(buffer));

		if (read_chars == 0)
		{
			if (*buffer_index == 0)
			{
				exit(EXIT_SUCCESS);
			}
		}
		if (read_chars == -1)
		{
			perror("read error");
			exit(EXIT_FAILURE);
		}

		*buffer_index = (size_t)read_chars;
	}
}
/**
 * process_buffer - f
 * @buffer: b
 * @buffer_index: inx
 * @line: line
 * @line_size: line
 */
void process_buffer(char *buffer, size_t *buffer_index, char **line, size_t *line_size)
{
	char *newline_pos = memchr(buffer, '\n', *buffer_index);
	size_t copy_chars = (newline_pos != NULL) ?
	       (size_t)(newline_pos - buffer + 1) : *buffer_index;

	*line = realloc(*line, *line_size + copy_chars);
	if (*line == NULL)
	{
		perror("realloc error");
		exit(EXIT_FAILURE);
	}
	memcpy(*line + *line_size, buffer, copy_chars);

	*buffer_index -= copy_chars;
	*line_size += copy_chars;

	if (newline_pos != NULL)
	{
		break;
	}
}
