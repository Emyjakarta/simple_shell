#include "_shell.h"
/**
 * _execute_absolute_path-execute absolute path
 * @_copy_command: copy of command
 * @str: pointer to an array of strings
 * Return: void
 */
void _execute_absolute_path(const char *_copy_command, char *const str[])
{
	int Q, R;
	char *_copy_command_copy;
	char *_token1 = strtok((char *)_copy_command, " ");
	char *command_array[MAXIMUM_ARGUMENTS + 2];

	_copy_command_copy = strdup(_copy_command);
	while (_token1 != NULL && MAXIMUM_ARGUMENTS + 1 > R)
	{
		command_array[R++] = _token1;
		_token1 = strtok(NULL, " ");
	}
	command_array[R] = NULL;
	if (access(command_array[0], X_OK) == 0)
	{
		printf("Debug: Contents of the str array before execve:\n");
		for (Q = 0; command_array[Q] != NULL; ++Q)
		{
			printf("[%d]: %s\n", Q, str[Q]);
		}
		if (execve(command_array[0], command_array, environ) == -1)
		{
			perror("execve failed");
			printf("Error number: %d\n", errno);
			exit(1);
		}
	}
	else
	{
		fprintf(stderr, "Error: Unable to execute %s\n", _copy_command);
		exit(1);
	}
	free(_copy_command_copy);
}
