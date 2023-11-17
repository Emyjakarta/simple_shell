#include "_shell.h"

/**
 * obtain_path - Returns a pointer to the path variable
 * from the environmental variables of the system
 * @env: Environmental Variable
 * Return: Char *pointer to the paths
 */

char *obtain_path(char **env)
{
	char *_path = NULL;
	int Q = 0;

	while (env[Q])
	{
		if (_strstr(env[Q], "PATH") && env[Q][0] == 'P' && env[Q][4] == '=')
		{
			_path = env[Q];
			break;
		}
		Q++;
	}
	if (_path != NULL)
	{
		for (Q = 0; Q < 6; Q++)
			_path++;
	}

	return (_path);
}
