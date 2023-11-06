#include "_shell.h"
/**
 * _cleanup_after_command-clean up after command
 * @_command: command
 * @_path: path
 * Return: void
 */
void _cleanup_after_command(char **_command, char **_path)
{
	free(*_command);
	*_command = NULL;
	if (*_path != NULL)
	{
		free(*_path);
		*_path = NULL;
	}
}
/**
 * _update_path-update path
 * @_path: path
 * Return: void
 */
void _update_path(char **_path)
{
	*_path = malloc(PATH_MAX);
	if (*_path == NULL)
	{
		perror("malloc");
		exit(1);
	}
	if (getcwd(*_path, PATH_MAX) == NULL)
	{
		perror("getcwd");
		exit(1);
	}
}
/**
 * _cleanup_after_main-clean up after main
 * @_path: path
 * @_home: home
 * Return: void
 */
void _cleanup_after_main(char **_path, char **_home)
{
	if (*_path != NULL)
	{
		free(*_path);
		*_path = NULL;
	}
	if (*_home != NULL)
	{
		free(*_home);
		*_home = NULL;
	}
}
