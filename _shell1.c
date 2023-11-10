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
void _handle_cd_command(const char *_command)
{
	char *_new_dir = _get_cd_path(_command);
	char _current_dir[PATH_MAX];
	char *_oldpwd, *_home_dir;

	printf("Command input for cd: %s\n", _command);
	if (_new_dir == NULL || _new_dir[0] == '\0')
	{
		fprintf(stderr, "Error: Unable to parse directory from command\n");
		return;
	}
	if (strcmp(_new_dir, "~") == 0)
	{
		_home_dir = getenv("HOME");
		if (_home_dir != NULL)
		{
			strncpy(_new_dir, _home_dir, PATH_MAX - 1);
			_new_dir[PATH_MAX - 1] = '\0';
		}
	}
	else if (strcmp(_new_dir, "-") == 0)
	{
		_oldpwd = getenv("OLDPWD");
		if (_oldpwd != NULL)
		{
			strncpy(_new_dir, _oldpwd, PATH_MAX - 1);
			_new_dir[PATH_MAX - 1] = '\0';
		}
		else
		{
			fprintf(stderr, "OLDPWD not set\n");
			free(_new_dir), _new_dir = NULL;
			return;
		}
	}
	if (getcwd(_current_dir, PATH_MAX) == NULL)
	{
		perror("getcwd");
		free(_new_dir), _new_dir = NULL;
		return;
	}
	if (chdir(_new_dir) != 0)
	{
		perror("chdir");
		free(_new_dir), _new_dir = NULL;
		return;
	}
	else
	{
		setenv("OLDPWD", _current_dir, 1);
		setenv("PWD", _new_dir, 1);
	}
	free(_new_dir), _new_dir = NULL;
}
/**
 * _process_command_loop-process command in the main shell loop
 * @_command: command to be processed
 * @dir: directory
 * Return: void
 */
void _process_command_loop(char **_command,
		char *dir)
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
			if (strlen(*_command) >= MAXIMUM_COMMAND_LENGTH)
			{
				fprintf(stderr, "Error: Command length exceeds maximum\n");
				free(*_command), *_command = NULL;
				continue;
			}
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
	char *_command = NULL;
	char *_temp = getcwd(NULL, 0), *dir = NULL;
	char _current_directory[1024];

	if (strncpy(_current_directory, _temp,
				sizeof(_current_directory) - 1) != NULL)
		printf("This is the current working directory: %s\n", _current_directory);
	else
		perror("getcwd() error");
	strncpy(_current_directory, _temp, sizeof(_current_directory) - 1);
	_current_directory[sizeof(_current_directory) - 1] = '\0';
	free(_temp);
	_temp = NULL;
	if (argc != 2)
	{
		_process_command_loop(&_command, dir);
	}
	else if (argc == 2)
		_exe_command_from_file(argv[1]);
	else
	{
		printf("Usage: %s [filename]\n", argv[0]);
		return (EXIT_FAILURE);
	}
	return (0);
}
