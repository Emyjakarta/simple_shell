#include "_shell.h"
/**
 * _process_command-process command
 * @_command: command to be processed
 * Return: void
 */
void _process_command(const char *_command)
{
	char *str[MAXIMUM_ARGUMENTS + 1] = {NULL}, *_token;
	char *_copy_command = _strdup(_command);
	int Q = 0, R = 0, S;
	char *_token1;

	_token = _strtok(_copy_command, " ");
	while (_token != NULL)
	{
		_token1 = _strdup(_token);
		str[Q] = _token1;
		_token = _strtok(NULL, " ");
		Q++;
		if (MAXIMUM_ARGUMENTS <= Q)
			break;
	}
	str[Q] = NULL;
	for (S = 0; Q > S; S++)
	{
		free(str[S]);
		str[S] = NULL;
	}
	while (str[R] != NULL)
	{
		printf("%s\n", str[R]);
		R++;
	}
	free(_copy_command);
	_copy_command = NULL;
}
/**
 * _check_command-check command
 * @_command: command to be checked
 * Return: void
 */
char *_check_command(const char *_command)
{
	size_t _len = _strlen((char *)_command);
	char *_result;

	if (_command != NULL && _command[0] == '"'
			&& _command[_len - 1] == '"')
	{
		_result = (char *)malloc(_len - 1);
		if (_result != NULL)
		{
			_strncpy((char *)_result, (char *)_command + 1, _len - 2);
			_result[_len - 2] = '\0';
		}
		return (_result);
	}
	return (NULL);
}
