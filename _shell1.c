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
 * @_command: command
 * Return: void
 */
void _handle_cd_command(const char *_command)
{
	char *_new_dir = _get_cd_path(_command), *_home_dir;
	char _current_dir[PATH_MAX], *_oldpwd = getenv("OLDPWD");

	printf("Command input for cd: %s\n", _command);
	if (_new_dir == NULL || _new_dir[0] == '\0')
		_new_dir = getenv("HOME");
	if (getcwd(_current_dir, PATH_MAX) == NULL)
	{
		perror("getcwd");
		return;
	}
	if (strcmp(_new_dir, "~") == 0)
	{
		_home_dir = getenv("HOME");
		if (_home_dir != NULL)
			snprintf(_new_dir, PATH_MAX, "%s", _home_dir);
	}
	else if (strcmp(_new_dir, "-") == 0)
	{
		_oldpwd = getenv("OLDPWD");
		if (_oldpwd == NULL)
		{
			fprintf(stderr, "OLDPWD not set\n"), _safe_free((void **)&_new_dir);
			return;
		}
		_new_dir = _oldpwd;
	}
	if (chdir(_new_dir) != 0)
	{
		perror("chdir");
		_safe_free((void **)&_new_dir);
		return;
	}
	else
	{
		setenv("OLDPWD", _current_dir, 1);
		setenv("PWD", _new_dir, 1);
	}
	if (_new_dir != NULL && _new_dir != getenv("HOME") && _new_dir != _oldpwd)
		_safe_free((void **)&_new_dir);
}
/**
 * _process_command_loop-process command in the main shell loop
 * @_command: command to be processed
 * Return: void
 */
void _process_command_loop(char **_command)
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
			_handle_cd_command(*_command);
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

	if (argc != 2)
	{
		_process_command_loop(&_command);
	}
	else if (argc == 2)
		_exe_command_from_file(argv[1]);
	else
	{
		printf("Usage: %s [filename]\n", argv[0]);
		return (EXIT_FAILURE);
	}
	return (errno);
}
