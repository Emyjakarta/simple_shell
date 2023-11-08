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
 * @argv: command line argument
 * Return: void
 */
void _handle_cd_command(char **argv)
{
	char *path, home[1024], *_home = getenv("HOME");
	int retval;

	if (_home != NULL)
		_strcpy(home, _home);
	else
	{
		perror("HOME is not set");
		return;
	}
	if (argv[1] == NULL)
	{
		retval = chdir(home);
		if (retval != 0)
		{
			perror("chdir");
		}
	}
	else if (_strcmp(argv[1], "-") == 0)
	{
		path = getenv("OLDPWD");
		if (path == NULL)
		{
			perror("OLDPWD not set");
			return;
		}
		retval = chdir(path);
		if (retval != 0)
		{
			perror("chdir");
		}
	}
	else
	{
		retval = chdir(argv[1]);
		if (retval != 0)
		{
			perror("chdir");
		}
	}
}
/**
 * _process_command_loop-process command in the main shell loop
 * @_command: command to be processed
 * @_path: path
 * @argv: command line argument
 * Return: void
 */
void _process_command_loop(char **_command,
		char **_path, char **argv)
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
			_handle_cd_command(argv);
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
	char *_command = NULL, *_path = NULL;
	char *_temp = getcwd(NULL, 0);
	int Q;
	char _current_directory[1024];

	if (_strncpy(_current_directory, _temp,
				sizeof(_current_directory) - 1) != NULL)
		printf("This is the current working directory: %s\n", _current_directory);
	else
		perror("getcwd() error");
	_strncpy(_current_directory, _temp, sizeof(_current_directory) - 1);
	_current_directory[sizeof(_current_directory) - 1] = '\0';
	if (argc > 1)
	{
		for (Q = 0; argc > Q; Q++)
		{
			printf("Argument %d: %s\n", Q, argv[Q]);
		}
	}
	free(_temp);
	_temp = NULL;
	_process_command_loop(&_command, &_path, argv);
	_cleanup_after_main(&_path);
	return (0);
}
