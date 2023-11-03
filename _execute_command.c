#include "_shell.h"
/**
 * _exe_command-execute command
 * @_command: command to be executed
 * Return:void
 */
void _exe_command(const char *_command)
{
	pid_t _child_pid = fork();
	char *str[MAXIMUM_ARGUMENTS + 1] = {NULL}, *_token;
	char *_copy_command = strdup(_command), *_home;
	int Q = 0, _status;
	size_t _command_length = strlen(_copy_command);
	char *_temp_command = NULL;

	if (_command_length > 1 && _copy_command[0] == '"'
			&& _copy_command[_command_length - 1] == '"')
	{
		_temp_command = malloc(_command_length - 1);
		if (_temp_command != NULL)
		{
			memcpy(_temp_command, _copy_command + 1, _command_length - 2);
			_temp_command[_command_length - 2] = '\0';
			free(_copy_command);
			_copy_command = _temp_command;
		}
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
	if (_child_pid == - 1)
	{
		perror("fork");
		free(_copy_command);
		free(_temp_command);
		exit(1);
	}
	else if (_child_pid == 0)
	{
		if (execve(str[0], str, environ) == - 1)
		{
			perror("./shell");
			free(_copy_command);
			free(_temp_command);
			exit(1);
		}
	}
	else
	{
		waitpid(_child_pid, &_status, 0);
		free(_copy_command);
		free(_temp_command);
		if (str[0] != NULL && strcmp(str[0], "cd") == 0)
		{
			if (str[1] == NULL)
			{
				_home = getenv("HOME");
				if (_home != NULL)
				{
					chdir(_home);
				}
				else
				{
					perror("HOME not set");
				}
			}
			else
			{
				if (chdir(str[1]) != 0)
				{
					perror("chdir");
				}
			}
		}
	}
}
