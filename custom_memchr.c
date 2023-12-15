#include "shell.h"
/**
 * _memchr - fun
 * @s: s
 * @c: int
 * @n: size_t
 */
void *_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p = s;

	while (n--)
	{
		if (*p == (unsigned char)c)
		{
			return (void *)p;
		}
		p++;
	}
	return (NULL);
}
