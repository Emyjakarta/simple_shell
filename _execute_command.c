#include "_shell.h"
/**
 * _exe_command-execute command
 * @_command: command to be executed
 * Return:void
 */
void _exe_command(const char *_command)
{
	pid_t _child_pid = fork();
	char *str[3] = {NULL, NULL, NULL}, *_token;
	char *_copy_command = strdup(_command);

	_token = strtok(_copy_command, " ");
	if (_child_pid == -1)
	{
		perror("fork");
		free(_copy_command);
		exit(1);
	}
	else if (_child_pid == 0)
	{
		str[0] = _copy_command;
		if (_token != NULL)
		{
			if (strcmp(_token, "cd") == 0)
			{
				_token = strtok(NULL, " ");
				if (_token != NULL)
				{
					if (chdir(_token) != 0)
						perror("chdir");
				}
				else
					_putcharshell("provide a directory for the 'cd' command.\n");
				free(_copy_command);
				exit(0);
			}
		}
		if (execve(_copy_command, str, environ) == -1)
		{
			perror("execve");
			free(_copy_command);
			exit(1);
		}
	}
	else
		wait(NULL);
}
