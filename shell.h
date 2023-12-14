#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stddef.h>

#include <sys/wait.h>
#include <string.h>

#define READ_SIZE 1024
extern char **environ;

void _putchar(const char *string);
void display_prompt(void);
char *my_getline(void);
void execute_command(char *command);
char *custom_strtok(char **str_ptr);
void execute_exit(char *token);
void execute_setenv(void);
void execute_unsetenv(void);
void execute_cd(char *token);
void execute_and(char *token, int status);
void execute_env(void);
void execute_other(char *token, int status);
void find_and_execute_command(char *executable_path,
		char *args[], int *status);
void execute_command_in_child(char *executable_path, char *args[]);
char *read_input(size_t *read_chars);
char *process_buffer(char *buffer, size_t *buffer_index, size_t *line_size);
void execute_external(char *args[], int status);
char *_memcpy(char *dest, char *src, unsigned int n);
int _atoi(char *s);
void *_memchr(const void *s, int c, size_t n);
void *_realloc(void *ptr, size_t size);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
char *_strcpy(char *dest, char *src);

#endif
