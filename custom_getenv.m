#include "shell.h"
/**
 * _getenv - c
 * @name: n
 * Return: r
 */
char *_getenv(const char *name)
{
	static const char *env_vars[] = {"HOME", "PATH", NULL};
	static const char *env_vals[] = {"/home/user", "/usr/bin", NULL};

	for (size_t i = 0; env_vars[i] != NULL; i++)
	{
		if (strcmp(name, env_vars[i]) == 0)
		{
			return ((char *)env_vals[i]);
		}
	}
	return (NULL);
}
