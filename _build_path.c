#include "_shell.h"
/**
 * build_path-build path for ordinary commands like ls
 * @_command: command
 * Return: The built path to the executable
 */
char *build_path(const char *_command[])
{
	char *_path = getenv("PATH");
	char *_copy_path = strdup(_path);
	char *dir = strtok(_copy_path, ":");
	char _full_path[PATH_MAX];
	char *_build_path = NULL;
	size_t _dir_len, _command_len;
	const char *ERROR_MSG = "PATH length exceeds maximum length\n";

	while (dir != NULL)
	{
		_dir_len = _strlen(dir);
		_command_len = _strlen(_command[0]);
		if (_dir_len + 1 + _command_len >= PATH_MAX)
		{
			write(STDERR_FILENO, ERROR_MSG, _strlen(ERROR_MSG));
			break;
		}
		_strcpy(_full_path, dir);
		_full_path[_dir_len] = '/';
		_strcpy(_full_path + _dir_len + 1, _command[0]);
		if (access(_full_path, X_OK) == 0)
		{
			_build_path = strdup(_full_path);
			break;
		}
		dir = strtok(NULL, ":");
	}
	free(_copy_path);
	return (_build_path);
}
