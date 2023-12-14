#include "shell.h"
#include <stdlib.h>
/**
 * _realloc - f
 * @ptr: ptr
 * @size: size
 * Return: N
 */
void *_realloc(void *ptr, size_t size)
{
	if (ptr == NULL)
		return (malloc(size));

	void *new_ptr = malloc(size);

	if (new_ptr != NULL)
	{
		_memcpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}
