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
	char *_token = strtok(_copy_command, ";");
	char *_sep_command_token;

	while (_token != NULL && MAXIMUM_ARGUMENTS > Q)
	{
		_sep_command_token = strtok(_token, " \t\n\r");
		while (_sep_command_token != NULL && MAXIMUM_ARGUMENTS > Q)
		{
			str[Q++] = _sep_command_token;
			_sep_command_token = strtok(NULL, " \t\n\r");
		}
		_token = strtok(NULL, ";");
	}
	str[Q] = NULL;
	printf("Debug: Contents of the str array:\n");
	for (R = 0; str[R] != NULL; R++)
	{
		printf("[%d]: %s\n", R, str[R]);
	}
	free(_copy_command);
}
