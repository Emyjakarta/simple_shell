#include "_shell.h"
/**
 * _scan_command-read the command
 * @_command: command
 * @length: size of the command
 */
void _scan_command(char **_command, size_t length)
{
	size_t _buffer_size = 0;
	char *_command1 = NULL;

	if (isatty(STDIN_FILENO))
	{
		_show_prompt();
		fflush(stdout);
	}
	length = getline(&_command1, &_buffer_size, stdin);
	if (length <= 0)
	{
		free(_command1);
		*_command = NULL;
		return;
	}
	if (_command1[length - 1] == '\n')
		(_command1)[length - 1] = '\0';
	*_command = _command1;
}
