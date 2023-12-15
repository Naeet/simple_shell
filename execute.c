#include "shell.h"
void execute_command(char *command)
{
	pid_t child_pid;
	int status;
	char *token;
	char *args[10];

	token = strtok(command, " \t\n");

	if (!token)
	{
		return;
	}
	args[0] = token;

	for (int i = 1; i < 10; i++)
	{
		token = strtok(NULL, " \t\n");

		if (!token)
		{
			args[i] = NULL;
			break;
		}
		args[i] = token;
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
