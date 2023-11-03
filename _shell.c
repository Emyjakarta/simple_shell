#include "_shell.h"
/**
 * main-implement the functionalities of a simple shell
 * @argc: number of command line arguments
 * @argv: argument vector(array of strings that represent the arguments)
 * Return:Always 0 (success)
 */
int main(int argc, char **argv)
{	char *_command = NULL, *_path, *_home;
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
		}
		else if (_is_cd(_command))
		{
			_path = _get_cd_path(_command);
			if (_path == NULL)
			{
				_home = getenv("HOME");
				if (_home != NULL)
				{
					if (chdir(_home) != 0)
						perror("chdir");

				}
				else
					perror("HOME not set");
			}
			else
			{
				if (chdir(_path) != 0)
				{
					perror("chdir");
				}
				free(_path);
			}
			free(_command);
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
