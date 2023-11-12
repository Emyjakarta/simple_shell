#include "_shell.h"
/**
 * _scan_command-read the command
 * @_command: command
 */
void _scan_command(char **_command)
{
	size_t _buffer_size = 0;
	ssize_t _read_return_value;
	char *_command1 = NULL, *_comment_post;
	char *_semicolon_post;

	if (isatty(STDIN_FILENO))
	{
		_show_prompt();
		fflush(stdout);
	}
	_read_return_value = _getline(&_command1, &_buffer_size, stdin);
	if (_read_return_value > 0)
	{
		_comment_post = strchr(_command1, '#');
		if (_comment_post != NULL)
		{
			*_comment_post = '\0';
		}
		if (_command1[_read_return_value - 1] == '\n')
		{
			_command1[_read_return_value - 1] = '\0';
		}
		_semicolon_post = strchr(_command1, ';');
		if (_semicolon_post != NULL)
		{
			*_semicolon_post = '\0';
		}
	}
	if (_read_return_value <= 0)
	{
		free(_command1);
		_command1 = NULL;
		*_command = NULL;
		return;
	}
	if (_command != NULL)
		free(*_command);
	*_command = _command1;
}
