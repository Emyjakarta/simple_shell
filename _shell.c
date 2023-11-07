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
 * @_command: command
 * @_home: pointer to the variable that stores the home
 * Return: void
 */
void _handle_cd_command(char **_command, char **_home)
{
	char _current_directory[1024], *_previous_directory = NULL;
	char *_path_arg = _get_cd_path(*_command);
	char *_temp = getcwd(NULL, 0), *_target_dir = NULL;
	
	if (*_command == NULL || strlen(*_command) == 0)
	{
		_target_dir = getenv("HOME");
		if (_target_dir != NULL)
		{
			if (chdir(_target_dir) != 0)
				perror("chdir");
			free(_target_dir);
			_target_dir = NULL;
		}
		else
			fprintf(stderr, "Error: HOME is not set\n");
	}
	if (_path_arg == NULL)
	{
		if (*_home != NULL)
		{
			if (_current_directory != NULL && 
					strcmp(_current_directory, *_home) != 0) 
			if (strcmp(_current_directory, *_home) != 0)
			{
				_previous_directory = strdup(_current_directory);
				if (chdir(*_home) != 0)
					perror("chdir");
				strncpy(_current_directory, *_home, sizeof(_current_directory) - 1);
			}
		}
		else
			perror("HOME not set");
	}
	else if (strcmp(_path_arg, "..") == 0)
	{
		if (_current_directory != NULL)
		{
			_previous_directory = strdup(_current_directory);
			if (chdir("..") != 0)
				perror("chdir");
			strncpy(_current_directory, _temp, sizeof(_current_directory) - 1);
			free(_temp);
			_temp = NULL;
		}
	}
	else if (strcmp(_path_arg, "-") == 0)
	{
		if (_previous_directory != NULL)
		{
			_temp = _previous_directory;
			_previous_directory = _current_directory;
			strncpy(_current_directory, _temp, sizeof(_current_directory) - 1);
			if (chdir(_temp) != 0)
			{
				perror("chdir");
			}
		}
		else
		{
			fprintf(stderr, "There is no previous directory\n");
		}
	}
	else 
	{
		if (_current_directory != NULL)
		{
			_previous_directory = strdup(_current_directory);
			if (chdir(_path_arg) != 0)
			{
				perror("chdir");
			}
			strncpy(_current_directory, _temp, sizeof(_current_directory) - 1);
		}
	}
	free(_path_arg);
	_path_arg = NULL;
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
			_handle_cd_command(_command, _home);
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
	char *_temp = getcwd(NULL, 0);
	int Q;
	char _current_directory[1024];

	if (strncpy(_current_directory, _temp, sizeof(_current_directory) - 1) != NULL)
		printf("This is the current working directory: %s\n", _current_directory);
	else
		perror("getcwd() error");
	strncpy(_current_directory, _temp, sizeof(_current_directory) - 1);
	_home = getenv("HOME");
	if (argc > 1)
	{
		for (Q = 0; argc > Q; Q++)
		{
			printf("Argument %d: %s\n", Q, argv[Q]);
		}
	}
	_process_command_loop(&_command, &_path, &_home);
	_cleanup_after_main(&_path, &_home);
	return (0);
}
