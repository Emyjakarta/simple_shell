#include "_shell.h"
/**
 * _execute_child_process-execute child process
 * @_command: command to be executed
 * @str: pointer to an array of strings
 * Return: void
 */
void _execute_child_process(const char *_command, char **str)
{
	char *_path = _strdup(getenv("PATH"));
	char *_token = _strtok(_path, ":");
	char *_full_path = _strdup(_token);
	char *_temp_full_path;

	if (_command == NULL || str == NULL)
	{
		fprintf(stderr, "Error: command or arguments are NULL)");
		return;
	}
	while (_token != NULL)
	{
		_temp_full_path = _strcat(_token, (char *)_command);
		if (access(_temp_full_path, X_OK) != 0)
		{
			perror("access");
			free(_temp_full_path);
			_temp_full_path = NULL;
			return;
		}
		if (access(_temp_full_path, X_OK) == 0)
		{
			if (execve(_temp_full_path, str, environ) == -1)
			{
				perror("execve");
				free(_temp_full_path);
				_temp_full_path = NULL;
				exit(1);
			}
		}
		_token = _strtok(NULL, ":");
	}
	fprintf(stderr, "Command not found in PATH\n");
	free(_path), _path = NULL;
	free(_full_path), _full_path = NULL;
}
/**
 * _wait_for_child_process-wait for child process
 * @_child_pid: process id of the child
 * @_status: status of the child process
 * Return: void
 */
void _wait_for_child_process(pid_t _child_pid,
		int *_status)
{
	waitpid(_child_pid, _status, 0);
}
/**
 * _execute_command_logic-execute command logic
 * including setenv and unsetenv
 * @_command: command to be executed
 * @str: pointer to an array of strings
 * Return: void
 */
void _execute_command_logic(const char *_command, char **str)
{
	pid_t _child_pid;
	int _status;

	if (_strcmp(_command, "setenv") == 0)
	{
		if (str[1] && str[2])
			_setenv(str[1], str[2]);
		else
			fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
	}
	else if (_strcmp(_command, "unsetenv") == 0)
	{
		if (str[1])
			_unsetenv(str[1]);
		else
			fprintf(stderr, "Usage: unsetenv VARIABLE\n");
	}
	if (_strcmp(_command, "cd") == 0)
	{
		if (str[1])
			_handle_cd_command(str[1]);
		else
			_handle_cd_command("~");
	}
	else
	{
		_child_pid = fork();
		_check_command(_command);
		_process_command(_command);
		if (_child_pid == -1)
			perror("fork"), exit(1);
		else if (_child_pid == 0)
		{
			_tokenize_command(_command, str);
			_execute_child_process(_command, str);
		}
		else
			_wait_for_child_process(_child_pid, &_status);
	}
}
/**
 * _execute_command-execute command
 * @_command: command to be executed
 * Return: void
 */
void _execute_command(const char *_command)
{
	char *str[MAXIMUM_ARGUMENTS + 1] = {NULL};

	if (_command[0] == '\0' || _command[0] == '\n')
	{
		return;
	}
	_execute_command_logic(_command, str);
}
