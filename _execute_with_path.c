#include "_shell.h"
/**
 * _create_full_path-create full path
 * @token: token
 * @command: command
 * Return: copy of the full path
 */
char *_create_full_path(const char *token, const char *command)
{
	char _full_path[PATH_MAX];

	snprintf(_full_path, sizeof(_full_path), "%s/%s", token, command);
	return (strdup(_full_path));
}
/**
 * _execute_command_with_full_path-execute command
 * @_full_path: full path
 * @str: pointer to an array of strings
 * @_copy_command: copy of the command
 * @_copy_path: copy of the path
 * Return: void
 */
void _execute_command_with_full_path(const char *_full_path, char **str,
		char *_copy_command, char *_copy_path)
{
	if (execve(_full_path, str, environ) == -1)
	{
		perror("execve failed");
		printf("Error number: %d\n", errno);
		free(_copy_command);
		_copy_command = NULL;
		free(_copy_path);
		_copy_path = NULL;
		exit(1);
	}
}
/**
 * _unknown_command_exit-if the command is not found exit
 * @command: command
 * @_copy_command: copy of the command
 * @_copy_path: copy of the path
 */
void _unknown_command_exit(const char *command,
		char *_copy_command, char *_copy_path)
{
	fprintf(stderr, "%s: command is not found\n", command);
	free(_copy_command);
	_copy_command = NULL;
	free(_copy_path);
	_copy_path = NULL;
	exit(1);
}
/**
 * _execute_commands_with_path-execute command with path
 * @str: pointer to a pointer to an array
 * @_copy_path: copy the original path
 * @_copy_command: copy the original command
 * Return: void
 */
void _execute_commands_with_path(char **str,
		char *_copy_path, char *_copy_command)
{
	char _full_path[PATH_MAX], *_token1;

	_token1 = strtok(_copy_path, ":");
	while (_token1 != NULL)
	{
		strcpy(_full_path, _create_full_path(_token1, str[0]));
		printf("Full path to execute: %s\n", _full_path);
		if (access(_full_path, X_OK) == 0)
		{
			_execute_command_with_full_path(_full_path, str,
					_copy_command, _copy_path);
		}
		_token1 = strtok(NULL, ":");
		memset(_full_path, 0, sizeof(_full_path));
	}
	_unknown_command_exit(str[0], _copy_command, _copy_path);
}
/**
 * _execute_with_path-execute commands with path
 * @str: pointer to an array of strings
 * @_copy_path: copy of the path
 * @_copy_command: copy of the command
 */
void _execute_with_path(char **str,
		char *_copy_path, char *_copy_command)
{
	_execute_commands_with_path(str, _copy_path, _copy_command);
}
