#include "_shell.h"
/**
 * _exe_command-execute command
 * @_command: command to be executed
 * Return:void
 */
void _exe_command(const char *_command)
{
	pid_t _child_pid;
	char *str[MAXIMUM_ARGUMENTS + 1] = {NULL}, *_token;
	char *_copy_command = strdup(_command);
	int Q = 0, _status;

	if (_command[0] == '\0' || _command[0] == '\n')
		return;
	_child_pid = fork();

	if (_command[0] == '"' && _command[strlen(_command) - 1] == '"')
	{
		_copy_command = strndup(_command + 1, strlen(_command) - 2);
	}
	_token = strtok(_copy_command, " ");
	while (_token != NULL)
	{
		str[Q] = _token;
		_token = strtok(NULL, " ");
		Q++;
		if (MAXIMUM_ARGUMENTS <= Q)
			break;
	}
	str[Q] = NULL;
	if (_child_pid == -1)
	{
		perror("fork");
		free(_copy_command);
		exit(1);
	}
	else if (_child_pid == 0)
	{
		if (execve(str[0], str, environ) == -1)
		{
			perror(str[0]);
			free(_copy_command);
			exit(1);
		}
	}
	else
	{
		waitpid(_child_pid, &_status, 0);
		free(_copy_command);
	}
}
