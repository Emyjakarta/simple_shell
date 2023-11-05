#include "_shell.h"
/**
 * main-implement the functionalities of a simple shell
 * @argc: number of command line arguments
 * @argv: argument vector(array of strings that represent the arguments)
 * Return:Always 0 (success)
 */
int main(int argc, char **argv)
{
	char *_command = NULL, *_path = NULL, *_home = NULL;
	(void) argc;
	(void)argv;

	_home = getenv("HOME");
	while (1)
	{
		_scan_command(&_command);
		if (_command == NULL)
		{
			break;
		}
		else if (_is_exit(_command))
		{
			free(_command);
			_command = NULL;
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
				_path = NULL;
			}
			free(_command);
			_command = NULL;
		}
		else if (_is_wildcard(_command))
		{
			_putcharshell("Handle wildcard\n");
		}
		else
		{
			_exe_command(_command);
		}
		free(_command);
		_command = NULL;
		if (_path != NULL)
		{
			free(_path);
			_path = NULL;
		}
		_path = malloc(PATH_MAX);
		if (_path == NULL)
		{
			perror("malloc");
			exit(1);
		}
		if (getcwd(_path, PATH_MAX) == NULL)
		{
			perror("getcwd");
			exit(1);
		}
	}
	if (_path != NULL)
	{
		printf("_path: %s\n", _path);
		free(_path);
		_path = NULL;
	}
	if (_home != NULL)
	{
		printf("_home: %s\n", _home);
	}
	return (0);
}
