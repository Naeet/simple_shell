#include "shell.h"
/**
 * execute_exit - e
 * @token: c
 */
void execute_exit(char *token)
{
	int status = 0;

	token = strtok(NULL, " \t\n");
	if (token)
	{
		status = _atoi(token);
	}

	if (status != 0)
	{
	_exit(status);
	}
}
/**
 * execute_setenv - f
 */
void execute_setenv(void)
{
	char *var = strtok(NULL, " \t\n");
	char *value = strtok(NULL, " \t\n");

	if (!var || !value)
	{
		_putchar("Usage: setenv VARIABLE VALUE\n");
	}
	else
	{
		if (setenv(var, value, 1) != 0)
		{
			perror("setenv error");
		}
	}
}
/**
 * execute_unsetenv - f
 */
void execute_unsetenv(void)
{
	char *var = strtok(NULL, " \t\n");

	if (!var)
	{
		_putchar("Usage: unsetenv VARIABLE\n");
	}
	else
	{
		if (unsetenv(var) != 0)
		{
			perror("unsetenv error");
		}
	}
}
/**
 * execute_cd - f
 * @token: c
 */
void execute_cd(char *token)
{
	char *oldpwd;

	token = strtok(NULL, " \t\n");

	if (!token)
	{
		token = getenv("HOME");
	}
	oldpwd = getenv("PWD");

	if (oldpwd == NULL)
	{
		perror("getenv error");
		return;
	}
	if (chdir(token) != 0)
	{
		perror("chdir error");
	}
	else
	{
		char *newpwd = getcwd(NULL, 0);

		if (newpwd == NULL)
			perror("getcwd error");
		else
		{
			if (setenv("PWD", newpwd, 1) != 0)
			{
				perror("setenv error");
			}
			/*
			putchar(newpwd);
			*/
			free(newpwd);
		}
	}
	if (setenv("OLDPWD", oldpwd, 1) != 0)
	{
		perror("setenv error");
	}
}
/**
 * execute_and - f
 * @token: c
 * @status: i
 */
void execute_and(char *token, int status)
{
	if (status == 0)
	{
		token = strtok(NULL, " \t\n");
		if (token)
		{
			execute_command(token);
		}
	}
}
