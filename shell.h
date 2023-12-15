#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#include <string.h>
#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64
void display_prompt(void);
char *read_input(void);
void execute_command(char *command);
void find_and_execute_command(char *executable_path, char *args[], int *status);
void execute_other(char *token, int status);
void execute_external(char *args[], int status);
void execute_exit(char *token);

#endif /* SHELL_H */

