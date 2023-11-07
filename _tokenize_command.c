#include "_shell.h"
/**
 * _tokenize_command-tokenize command
 * @_command: pointer to a const char (input command)
 * like ls -l /tmp
 * @str: array of pointers to strings where the
 * extracted words from the input command will be stored
 * Return: void
 */
void _tokenize_command(const char *_command, char **str)
{
	int Q = 0, R;
	char *_copy_command = strdup(_command);
	char *_token = strtok(_copy_command, " ");

	while (_token != NULL)
	{
		str[Q] = strdup(_token);
		_token = strtok(NULL, " ");
		Q++;
		if (MAXIMUM_ARGUMENTS <= Q)
			break;
	}
	str[Q] = NULL;
	for (R = 0; Q > R; R++)
	{
		free(str[R]);
		str[R] = NULL;
	}
}
