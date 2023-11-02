#include "_shell.h"
/**
 * _is_exit-check if it is exit command
 * @_command: command to be checked
 * Return: 1 if the command is exit or EOF
 */
int _is_exit(const char *_command)
{
	return (strcmp(_command, "exit") == 0 || strcmp(_command, "EOF") == 0);
}
/**
 * _is_wildcard-check if it is a wildcard
 * @_command: command to be checked
 * Return: 1 if the command is a wildcard character
 */
int _is_wildcard(const char *_command)
{
	return (strpbrk(_command, "*?") != NULL);
}
