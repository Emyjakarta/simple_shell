#ifndef _SHELL_H
#define _SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

#define MAXIMUM_COMMAND_LENGTH 500
#define MAXIMUM_ARGUMENTS 30

extern char **environ;
int main(int argc, char **argv);
char _putcharshell(const char *str);
void _show_prompt(void);
void _scan_command(char **_command);
int _is_exit(const char *_command);
int _is_cd(const char *_command);
char *_get_cd_path(const char *_command);
int _is_wildcard(const char *_command);
void _exe_command(const char *_command);

char *obtain_path(char *_command, char **envp);

#endif /*_SHELL_H */
