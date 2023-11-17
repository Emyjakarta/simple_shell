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
	int Q;

	printf("Debug: Contents of the _command array:\n");
	for (Q = 0; _command[Q] != NULL; ++Q)
	{
		printf("[%d]: %s\n", Q, _command[Q]);
	}
	while (dir != NULL)
	{
		snprintf(_full_path, sizeof(_full_path), "%s/%s", dir, _command[0]);
		printf("Debug: Trying _path: %s\n", _full_path);
		if (access(_full_path, X_OK) == 0)
		{
			_build_path = strdup(_full_path);
			break;
		}
		dir = strtok(NULL, ":");
	}
	free(_copy_path);
	printf("Debug: Contents of the _build_path: %s\n", _build_path);
	return (_build_path);
}
