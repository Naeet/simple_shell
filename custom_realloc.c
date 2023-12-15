#include "shell.h"
/**
 * _realloc - fun
 * @ptr: ptr
 * @size: size
 */
void *custom_realloc(void *ptr, size_t size)
{
	void *new_ptr = malloc(size);

	if (ptr == NULL)
	{
		return malloc((size));
	}

	if (new_ptr != NULL)
	{
		_memcpy(new_ptr, ptr, size);
		free(ptr);
	}

	return (new_ptr);
}
