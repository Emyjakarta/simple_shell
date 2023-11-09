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
 * _handle_cd_command-handle cd command
 * @dir: directory
 * Return: void
 */
void _handle_cd_command(char *dir)
{
	char *_new_dir = NULL;
	char _current_dir[PATH_MAX];

	if (dir == NULL || _strcmp(dir, "~") == 0 ||
			_strcmp(dir, "$HOME") == 0)
	{
		_new_dir = getenv("HOME");
	}
	else if (_strcmp(dir, "-") == 0)
	{
		_new_dir = getenv("OLDPWD");
	}
	else
	{
		_new_dir = dir;
	}
	if (getcwd(_current_dir, PATH_MAX) == NULL)
	{
		perror("getcwd");
		return;
	}
	if (chdir(_new_dir) != 0)
	{
		perror("chdir");
	}
	else
	{
		setenv("OLDPWD", _current_dir, 1);
		setenv("PWD", _new_dir, 1);
	}
}
/**
 * _process_command_loop-process command in the main shell loop
 * @_command: command to be processed
 * @_path: path
 * @dir: directory
 * Return: void
 */
void _process_command_loop(char **_command,
		char **_path, char *dir)
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
			_handle_cd_command(dir);
		}
		else if (_is_wildcard(*_command))
		{
			_handle_wildcard();
		}
		else
		{
			_execute_command(*_command);
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
	char *_temp = getcwd(NULL, 0), *dir = NULL;
	char _current_directory[1024];

	if (_strncpy(_current_directory, _temp,
				sizeof(_current_directory) - 1) != NULL)
		printf("This is the current working directory: %s\n", _current_directory);
	else
		perror("getcwd() error");
	_strncpy(_current_directory, _temp, sizeof(_current_directory) - 1);
	_current_directory[sizeof(_current_directory) - 1] = '\0';
	free(_temp);
	_temp = NULL;
	if (argc != 2)
	{
		_process_command_loop(&_command, &_path, dir);
	}
	else if (argc == 2)
		_exe_command_from_file(argv[1]);
	else
	{
		printf("Usage: %s [filename]\n", argv[0]);
		return (EXIT_FAILURE);
	}
	_cleanup_after_main(&_path);
	return (0);
}
