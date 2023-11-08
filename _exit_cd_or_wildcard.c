#include "_shell.h"
/**
 * _is_exit-check if it is exit command
 * @_command: command to be checked
 * Return: 1 if the command is exit or EOF
 */
int _is_exit(const char *_command)
{
	return (_strcmp((char *)_command, "exit") == 0 ||
			_strcmp(_command, "EOF") == 0);
}
/**
 * _is_cd-check if it is cd command
 * @_command: command to be checked
 * Return: 1 if the command is cd, 0 otherwise
 */
int _is_cd(const char *_command)
{
	return (_strncmp(_command, "cd", 2) == 0);
}
/**
 * _get_cd_path-locate cd path once it is cd
 * @_command: command to be checked
 * Return: pointer to the string containing path following cd
 */
char *_get_cd_path(const char *_command)
{
	char *_ptr_space = _strchr((char *)_command, ' ');

	if (_ptr_space == NULL)
		return (NULL);
	else
		return (_strdup(_ptr_space + 1));
}
/**
 * _is_wildcard-check if it is a wildcard
 * @_command: command to be checked
 * Return: 1 if the command is a wildcard character
 */
int _is_wildcard(const char *_command)
{
	return (_strpbrk((char *)_command, "*?") != NULL);
}
