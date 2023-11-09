#ifndef _SHELL_H
#define _SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>

#define MAXIMUM_COMMAND_LENGTH 500
#define MAXIMUM_ARGUMENTS 30
#define INITIAL_BUFFER_SIZE 128
#define MAX_BUFFER_SIZE 1024

extern char **environ;
extern char _current_directory[1024];
extern char *_previous_directory;
extern char home[1024];
extern char **argv;
/**
 * struct _alias-alias
 * @name: name of the alias
 * @value: value given to the alias
 * @next: pointer to the next node
 *
 * Description: define built in alias
 */
typedef struct _alias
{
	char *name;
	char *value;
	struct alias *next;
} _alias;
char *_strcat(char *dest, char *src);
char *_memset(char *s, char b, unsigned int n);
char *_strncat(char *dest, char *src, int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(const char *s1, const char *s2);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, char *src);
char *str_concat(char *s1, char *s2);
void freewords(char **words);
char **strtow(char *str);
char **wordpopulate(char **words, char *str);
char *wordextract(char *start, int length);
int wordcount(char *str);
char *argstostr(int ac, char **av);
char *_strdup(const char *str);
int _strncmp(const char *str1, const char *str2, size_t num);
char *_strtok(char *str, const char *delim);
ssize_t _getline(char **ptr_line, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
void *_copy_memory(void *dest, const void *src, size_t size);

void _setenv(const char *var, const char *value);
void _unsetenv(const char *var);

void _handle_cd_command(char *dir);
void _cleanup_after_command(char **_command, char **_path);
void _update_path(char **_path);
void _process_command_loop(char **_command,
		char **_path, char *dir);
void _cleanup_after_main(char **_path);
int main(int argc, char **argv);
char _putcharshell(const char *str);
void _show_prompt(void);
void _scan_command(char **_command);
int _is_exit(const char *_command);
int _is_cd(const char *_command);
char *_get_cd_path(const char *_command);
int _is_wildcard(const char *_command);
void _tokenize_command(const char *_command, char **str);
void _process_command(const char *_command);
char *_check_command(const char *_command);
void _execute_child_process(const char *_command, char **str);
void _wait_for_child_process(pid_t _child_pid,
		int *_status);
void _execute_command_logic(const char *_command, char **str);
void _execute_command(const char *_command);
char *_create_full_path(const char *command);
void _execute_command_with_full_path(const char *_full_path, char **str,
		char *_copy_command, char *_copy_path);
void _unknown_command_exit(const char *command,
		char *_copy_command, char *_copy_path);
void _execute_commands_with_path(char **str,
		char *_copy_path, char *_copy_command);
void _execute_with_path(char **str,
		char *_copy_path, char *_copy_command);
void _exe_command_from_file(const char *_filename);
char *_replace_var(char *_command);
int _get_exit_status(void);

char *obtain_path(char *_command, char **envp);

#endif /*_SHELL_H */
