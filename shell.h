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
void interactive_mode(void);
void non_interactive_mode(char *script_path);
#endif /* SHELL_H */

