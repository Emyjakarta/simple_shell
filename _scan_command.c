#include "_shell.h"
/**
 * _scan_command-read the command
 * @_command: command
 */
void _scan_command(char **_command)
{
	size_t _buffer_size = 0;
	ssize_t _read_return_value;
	char *_command1 = NULL;

	if (isatty(STDIN_FILENO))
	{
		_show_prompt();
		fflush(stdout);
	}
	_read_return_value = _get_line(&_command1, &_buffer_size, stdin);
	if (_read_return_value <= 0)
	{
		free(_command1);
		_command1 = NULL;
		*_command = NULL;
		return;
	}
	if (_read_return_value > 1 && _command1[_read_return_value - 1] == '\n')
		_command1[_read_return_value - 1] = '\0';
	if (_command != NULL)
		free(*_command);
	*_command = _command1;
}
