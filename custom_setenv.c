#include "shell.h"
/**
 * _setenv - f
 * @name: n
 * @value: v
 * @overwrite: o
 * Return: res
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	static char *env_vars[10];
	static char *env_vals[10];
	size_t i;

	for (i = 0; env_vars[i] != NULL; i++)
	{
		if (strcmp(name, env_vars[i]) == 0)
		{
			if (overwrite)
			{
				free(env_vals[i]);
				env_vals[i] = strdup(value);
				return (0);
			}
		else
			return (-1);
		}
	}

	if (i < 10)
	{
		env_vars[i] = strdup(name);
		env_vals[i] = strdup(value);
		return (0);
	}
	else
	{
		_putchar("custom_setenv: too many environment variables\n");
		return (-1);
	}
}

