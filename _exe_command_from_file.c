#include "_shell.h"
/**
 * _exe_command_from_file-execute command from file
 * @_filename: name of file
 * Return: void
 */
void _exe_command_from_file(const char *_filename)
{
	char *_line = NULL, *_replaced_command;
	size_t _len = 0;
	ssize_t _read;
	FILE *_file = fopen(_filename, "r");

	if (_file == NULL)
	{
		perror("File opening failed");
		exit(EXIT_FAILURE);
	}
	while ((_read = _getline(&_line, &_len, _file)) != -1)
	{
		if (_line[0] != '#' && _line[_read - 1] == '\n')
		{
			_line[_read - 1] = '\0';
			_replaced_command = _replace_var(_line);
			_execute_command(_line);
			free(_replaced_command);
		}
	}
	free(_line);
	fclose(_file);
}
