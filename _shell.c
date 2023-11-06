#include "_shell.h"
/**
 * _handle_wildcard-handle wildcard
 * Return: void
 */
void _handle_wildcard(void)
{
	_putcharshell("Handle wildcard\n");
}
/**
 * _execute_normal_command-execute normal command
 * @command: command
 * Return: void
 */
void _execute_normal_command(const char *command)
{
	_exe_command(command);
}
/**
 * _handle_cd_command-handle cd command
 * @_path: pointer to the variable that stores the cd path
 * @_home: pointer to the variable that stores the home
 * Return: void
 */
void _handle_cd_command(char **_command,
		char **_path, char **_home)
{
	char *_path_arg = _get_cd_path(*_command);

	if (_path_arg == NULL)
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
		if (chdir(_path_arg) != 0)
		{
			perror("chdir");
		}
		free(_path_arg);
		_path_arg = NULL;
	}
	free(*_command);
	*_command = NULL;
}
/**
 * _process_command_loop-process command in the main shell loop
 * @_command: command to be processed
 * @_path: path
 * @_home: home
 * Return: void
 */
void _process_command_loop(char **_command,
		char **_path, char **_home)
{
	while (1)
	{
		_scan_command(_command);
		if (*_command == NULL)
		{
			break;
		}
		else if (_is_exit(*_command))
		{
			free(*_command);
			*_command = NULL;
			break;
		}
		else if (_is_cd(*_command))
		{
			_handle_cd_command(_command, _path, _home);
		}
		else if (_is_wildcard(*_command))
		{
			_handle_wildcard();
		}
		else
		{
			_execute_normal_command(*_command);
		}
		_cleanup_after_command(_command, _path);
		_update_path(_path);
	}
}
/**
 * main-implement the functionalities of a simple shell
 * @argc: number of command line arguments
 * @argv: argument vector(array of strings that represent the arguments)
 * Return:Always 0 (success)
 */
int main(int argc, char **argv)
{
	char *_command = NULL, *_path = NULL, *_home = NULL;
	int Q;

	_home = getenv("HOME");
	if (argc > 1)
	{
		for (Q = 0; argc > Q; Q++)
		{
			printf("Argument %d: %s\n", Q, argv[Q]);
		}
	}
	_process_command_loop(&_command, &_path, &_home);
	cleanup_after_main(&_path, &_home);
	return (0);
}
