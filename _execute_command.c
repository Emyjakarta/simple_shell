#include "_shell.h"
/**
 * _execute_child_process-execute child process
 * @_command: command to be executed
 * @str: pointer to an array of strings
 * @_copy_command: copy of command
 * @_copy_path: copy of path
 * Return: void
 */
void _execute_child_process(const char *_command, char **str,
		char *_copy_command, char *_copy_path)
{
	int R = 0;
	char **command = malloc(sizeof(char *) * 2);

	if (command == NULL)
	{
		perror("malloc");
		exit(1);
	}
	command[0] = strdup(_command);
	command[1] = NULL;
	if (_strchr((char *)_command, '/') != NULL)
	{
		while (str[R] != NULL)
		{
			printf("str[%d] = %s\n", R, str[R]);
			R++;
		}
		if (execve(_command, str, environ) == -1)
		{
			perror(_command);
			exit(1);
		}
	}
	else
	{
		_execute_with_path(str, _copy_path, _copy_command);
	}
	free(command[0]);
	free(command);
	exit(0);
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
 * @_command: command to be executed
 * @str: pointer to an array of strings
 * @_copy_command: copy of command
 * @_copy_path: copy of path
 * Return: void
 */
void _execute_command_logic(const char *_command, char **str,
		char *_copy_command, char *_copy_path)
{
	pid_t _child_pid = fork();
	int _status;

	_process_command(_command);
	if (_child_pid == -1)
	{
		perror("fork");
		free(_copy_command);
		_copy_command = NULL;
		free(_copy_path);
		_copy_path = NULL;
		exit(1);
	}
	else if (_child_pid == 0)
	{
		_check_command(_command);
		_tokenize_command(_command, str);
		_execute_child_process(_command, str, _copy_command, _copy_path);
	}
	else
	{
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
	char *_path = getenv("PATH");
	char *_copy_command = strdup(_command);
	char *_copy_path = strdup(_path);

	if (_command[0] == '\0' || _command[0] == '\n')
	{
		free(_copy_command);
		_copy_command = NULL;
		free(_copy_path);
		_copy_path = NULL;
		return;
	}
	_execute_command_logic(_command, str, _copy_command, _copy_path);
	free(_copy_command);
	_copy_command = NULL;
	free(_copy_path);
	_copy_path = NULL;
}
/**
 * _exe_command-execute command
 * @_command: command to be executed
 * Return:void
 */
void _exe_command(const char *_command)
{
	_execute_command(_command);
}
