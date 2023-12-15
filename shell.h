#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;


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
int _atoi(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_memchr(const void *s, int c, size_t n);
void *_realloc(void *ptr, size_t size);
int _printf(const char *format, ...);
int _strcmp(char *s1, char *s2);

void execute_exit(char *token);
void execute_setenv(void);
void execute_unsetenv(void);
void execute_cd(char *token);
void execute_and(char *token, int status);
void execute_env(void);

static void process_buffer(char *buffer, size_t *buffer_index, char **line, size_t *line_size);
static void read_input(char buffer[], size_t *buffer_index);
char *_getline(void);

#endif /* SHELL_H */

