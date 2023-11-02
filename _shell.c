#include "_shell.h"
/**
 * main-implement the functionalities of a simple shell
 * @argc: number of command line arguments
 * @argv: argument vector(array of strings that represent the arguments)
 * Return:Always 0 (success)
 */
int main(int argc, char **argv)
{	char *_command = NULL;
	size_t _buffer_size = 0;
	(void) argc;
	(void)argv;

	while (1)
	{
		_scan_command(&_command, _buffer_size);
		if (_is_exit(_command))
		{
			free(_command);
			break;
			exit(0);
		}
		else if (_is_wildcard(_command))
		{
			_putcharshell("Handle wildcard\n");
		}
		else
			_exe_command(_command);
	}
	return (0);
}
