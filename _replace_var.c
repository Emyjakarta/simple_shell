#include "_shell.h"
/**
 * _replace_var-replace special variables in command string
 * @_command: command string
 * Return: Replaced command string
 */
char *_replace_var(char *_command)
{
	char *_replaced = NULL;
	char _pid[20];
	int Q, R = 0;

	_replaced = malloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (_replaced == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	_memset(_replaced, 0, MAX_BUFFER_SIZE);
	for (Q = 0; _command[Q] != '\0'; Q++)
	{
		if (_command[Q] == '$' && _command[Q + 1] == '$')
		{
			sprintf(_pid, "%d", getpid());
			strcat(_replaced, _pid);
			Q++;
			R += strlen(_pid);
		}
		else if (_command[Q] == '$' && _command[Q + 1] == '?')
		{
			sprintf(_pid, "%d", _get_exit_status());
			strcat(_replaced, _pid);
			Q++;
			R += strlen(_pid);
		}
		else
		{
			_replaced[R] = _command[Q];
			R++;
		}
	}
	return (_replaced);
}
