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
	int Q = 0, _status, R = 0;
	char *_full_path, *_token1, *_path = getenv("PATH");
	char *_copy_path = strdup(_path);

	if (_command[0] == '\0' || _command[0] == '\n')
	{
		free(_copy_command);
		_copy_command = NULL;
		free(_copy_path);
		_copy_path = NULL;
		return;
	}
	_tokenize_command(_command, str);
	_child_pid = fork();

	if (_command[0] == '"' && _command[strlen(_command) - 1] == '"')
	{
		if (_copy_command != NULL)
		{
			free(_copy_command);
			_copy_command = NULL;
		}
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
		_copy_command = NULL;
		free(_copy_path);
		_copy_path = NULL;
		exit(1);
	}
	else if (_child_pid == 0)
	{
		if (strchr(_command, '/') != NULL)
		{
			while (str[R] != NULL)
			{
				printf("str[%d] = %s\n", R, str[R]);
				R++;
			}
			if (execve(str[0], str, environ) == -1)
			{
				perror(str[0]);
				free(_copy_path);
				_copy_path = NULL;
				exit(1);
			}
		}
		else
		{
			_token1 = strtok(_copy_path, ":");
			while (_token1 != NULL)
			{
				_full_path = malloc(strlen(_token1) + strlen(str[0]) + 2);
				sprintf(_full_path, "%s/%s", _token1, str[0]);
				printf("Full path to execute: %s\n", _full_path);
				if (access(_full_path, X_OK) == 0)
				{
					if (execve(_full_path, str, environ) == -1)
					{
						perror("execve failed");
						printf("Error number: %d\n", errno);
						free(_full_path);
						_full_path = NULL;
						free(_copy_command);
						_copy_command = NULL;
						free(_copy_path);
						_copy_path = NULL;
						exit(1);
					}
				}
				free(_full_path);
				_full_path = NULL;
				_token1 = strtok(NULL, ":");
			}
			fprintf(stderr, "%s: command not found\n", str[0]);
			free(_copy_command);
			_copy_command = NULL;
			free(_copy_path);
			_copy_path = NULL;
			exit(1);
		}
	}
	else
	{
		waitpid(_child_pid, &_status, 0);
		free(_copy_command);
		_copy_command = NULL;
		if (_copy_path != NULL)
		{
			free(_copy_path);
			_copy_path = NULL;
		}
	}
}
