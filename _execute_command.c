#include "_shell.h"
/**
 * _execute_child_process-execute child process
 * @_command: command to be executed
 * @str: pointer to an array of strings
 * Return: void
 */
void _execute_child_process(const char *_command, char **str)
{
	char *_temp_full_path; 
	char *command_array[] = {(char *)_command, NULL};

	if (_command == NULL || str == NULL)
	{
		fprintf(stderr, "Error: command or arguments are NULL)");
		return;
	}
	_temp_full_path = build_path((const char **)command_array);
	printf("Debug: Contents of the _temp_full_path: %s\n", _temp_full_path);
	if (_temp_full_path == NULL)
	{
		fprintf(stderr, "Command not found in PATH\n");
		return;
	}
	if (execve(_temp_full_path, str, environ) == -1)
	{
		perror("execve");
		fprintf(stderr, "Failed to execute _command: %s\n", _temp_full_path);
	}
	free(_temp_full_path);
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

	if (strcmp(_command, "setenv") == 0)
	{
		if (str[1] && str[2])
			setenv(str[1], str[2], 1);
		else
			fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
	}
	else if (strcmp(_command, "unsetenv") == 0)
	{
		if (str[1])
			unsetenv(str[1]);
		else
			fprintf(stderr, "Usage: unsetenv VARIABLE\n");
	}
	else if (strcmp(_command, "cd") == 0)
	{
		if (str[1])
			_handle_cd_command(str[1]);
		else
			_handle_cd_command("~");
	}
	else
	{
		_check_command(_command);
		_process_command(_command);
		_child_pid = fork();
		if (_child_pid == -1)
			perror("fork"), exit(1);
		else if (_child_pid == 0)
		{
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
	_tokenize_command(_replace_var((char *)_command), str);
	if (_command[0] == '/')
	{
		_execute_absolute_path(_command, str);
	}
	else
	{
		_execute_command_logic(_command, str);
	}
}
