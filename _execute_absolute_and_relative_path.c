#include "_shell.h"
/**
 * _execute_absolute_path-execute absolute path
 * @_copy_command: copy of command
 * @str: pointer to an array of strings
 * Return: void
 */
void _execute_absolute_path(const char *_copy_command, char *const str[])
{
	int Q;

	if (access(_copy_command, X_OK) == 0)
	{
		printf("Debug: Contents of the str array before execve:\n");
		for (Q = 0; str[Q] != NULL; ++Q)
		{
			printf("[%d]: %s\n", Q, str[Q]);
		}
		if (execve(_copy_command, str, environ) == -1)
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
}
