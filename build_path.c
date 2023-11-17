#include "_shell.h"

/**
 * PATH_handler - handles when a command name is passed
 * @argv: Commandline argument passed in for program name
 * @env: Environment variables
 * @tok_arr: For command and argument
 * @count: Command count variable pointer (unused now)
 * Return: Returns -1 if it fails or 0 if it succeeds
 */

int PATH_handler(char **argv, char **env, char **tok_arr, int *count)
{
	char **_paths_array = break_path(obtain_path(env)), *full_path;
	int i = 0, len_str, execve_val, status = -1;
	pid_t _pid_val;

	(void)count;
	if (_paths_array == NULL)
		return (-1);

	while (_paths_array[i])
	{
		len_str = _strlen(_paths_array[i]) + _strlen(tok_arr[0]) + 2;
		full_path = malloc(len_str);
		_strcpy(full_path, _paths_array[i]);
		_strcat(full_path, "/");
		_strcat(full_path, tok_arr[0]);
		if (access(full_path, F_OK) == -1)
		{
			free(full_path), i++, errno = 127;
			continue;
		}
		else
		{
			status = 1, _pid_val = fork();
			if (_pid_val == -1)
				return (-1);
			else if (_pid_val == 0)
			{
				execve_val = execve(full_path, tok_arr, env);
				if (execve_val == -1)
					perror(argv[0]), exit(EXIT_FAILURE);
			}
			else
				wait(&status), free(full_path), errno = status;
			break;
		}
	}
	_free_array_tokens(_paths_array);
	return (status);
}
