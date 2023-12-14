#include "shell.h"
/**
 * _memchr - f
 * @s: i
 * @c: i
 * @n: s
 * Return: res
 */
void *_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p = s;

	while (n--)
	{
		if (*p == (unsigned char)c)
		{
			return ((void *)p);
		}
		p++;
	}
	return (NULL);
}
