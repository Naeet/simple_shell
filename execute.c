#include "shell.h"
char *command;
/**
 * execute_env - f
 */
void execute_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
/**
 * execute_other - f
 * @token: t
 * @status: s
 */
void execute_other(char *token, int status)
{
	int i;
	char *args[10], *path, *dir, path_copy[1024];

	args[0] = token;
	for (i = 1; i < 10; i++)
	{
		token = strtok(NULL, " \t\n");
		if (!token)
		{
			args[i] = NULL;
			break;
		}
		args[i] = token;
	}
	path = getenv("PATH");
	if (path)
	{
		strcpy(path_copy, path);
		dir = strtok(path_copy, ":");
		while (dir)
		{
			char *executable_path = malloc(strlen(dir) + strlen(args[0]) + 2);

			if (!executable_path)
			{
				perror("malloc error");
				exit(EXIT_FAILURE);
			}
			sprintf(executable_path, "%s/%s", dir, args[0]);
			if (access(executable_path, X_OK) == 0)
			{
				find_and_execute_command(executable_path, args, &status);
				free(executable_path);
				return;
			}
			free(executable_path);
			dir = strtok(NULL, ":");
		}
	}	fprintf(stderr, "%s: command not found\n", args[0]);
}
/**
 * find_and_execute_command - f
 * @executable_path: c
 * @args: c
 * @status: i
 */
void find_and_execute_command(char *executable_path, char *args[], int *status)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		execute_command_in_child(executable_path, args);
	}
	else
	{
		waitpid(child_pid, status, 0);
	}
}
/**
 * execute_command_in_child - f
 * @executable_path: c
 * @args: a
 * @status: i
 */
void execute_command_in_child(char *executable_path, char *args[])
{
	if (execve(executable_path, args, NULL) == -1)
	{
		perror("execve error");
		exit(EXIT_FAILURE);
	}
}
/**
 * execute_command - e
 * @command: i
 */
void execute_command(char *command)
{
	int status = 0;
	char *token;

	token = strtok(command, " \t\n");
	if (!token)
		return;

	if (strcmp(token, "exit") == 0)
		execute_exit(token);
	else if (strcmp(token, "setenv") == 0)
		execute_setenv();
	else if (strcmp(token, "unsetenv") == 0)
		execute_unsetenv();
	else if (strcmp(token, "cd") == 0)
		execute_cd(token);
	else if (strcmp(token, "&&") == 0)
		execute_and(token, status);
	else if (strcmp(token, "env") == 0)
		execute_env();
	else
		execute_other(token, status);

	token = strtok(NULL, " \t\n");
}
