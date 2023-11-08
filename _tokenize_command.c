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
	int Q = 0;
	char *_copy_command = _strdup(_command);
	char *_token = _strtok(_copy_command, " ");

	while (_token != NULL)
	{
		str[Q] = _strdup(_token);
		_token = _strtok(NULL, " ");
		Q++;
		if (MAXIMUM_ARGUMENTS <= Q)
			break;
	}
	str[Q] = NULL;
	free(_copy_command);
}
