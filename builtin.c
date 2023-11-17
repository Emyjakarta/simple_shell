#include "_shell.h"

/**
 * _builtins_handler - Prints all environment variables
 * @argv: Command line arguments
 * @env: Environment variables
 * @tok_arr: Tokenized user input
 * Return: status 1 on successfully finding command or -1 otherwise
 */

int _builtins_handler(char **argv, char **env, char **tok_arr)
{
	int _check = -1, Q = 0;

	_built_in cd_str = {"cd", cd_handler};
	_built_in exit_str = {"exit", exit_handler};
	_built_in env_str = {"env", _env_handler};

	_built_in *ptr[3];

	ptr[0] = &cd_str;
	ptr[1] = &exit_str;
	ptr[2] = &env_str;

	while (Q < 3)
	{
		if (_strcmp(tok_arr[0], ptr[Q]->com) == 0)
		{
			ptr[Q]->func(argv, env, tok_arr);
			_check = 1;
			break;
		}
		Q++;
	}

	return (_check);
}

/**
 * exit_handler - Builtin function that terminates current process
 * @argv: Argument vector from command line
 * @env: Environment variables
 * @tok_arr: Array of user entry token
 */

void exit_handler(char **argv, char **env, char **tok_arr)
{
	int _status;

	(void)env;

	if (tok_arr[1] && _strstr(tok_arr[1], "HBTN"))
	{
		error_msg(2, 1, argv[0], tok_arr[0], "Illegal number: HBTN");
		_free_array_tokens(tok_arr);
		errno = 2;
		exit(errno);
	}
	if (tok_arr[1] && _strstr(tok_arr[1], "-98"))
	{
		error_msg(2, 1, argv[0], tok_arr[0], "Illegal number: -98");
		_free_array_tokens(tok_arr);
		errno = 2;
		exit(errno);
	}
	if (tok_arr[1])
	{
		_status = atoi(tok_arr[1]);
		_free_array_tokens(tok_arr);
		errno = _status;
		exit(errno);
	}
	if (errno != 0)
	{
		_free_array_tokens(tok_arr);
		exit(2);
	}
	_free_array_tokens(tok_arr);
	exit(errno);
}

/**
 * cd_handler - Builtin function that changes current directory
 * @argv: Argument vector from command line
 * @env: Environment variables
 * @tok_arr: Array of user entry token
 */

void cd_handler(char **argv, char **env, char **tok_arr)
{
	char *_dir = NULL;
	size_t size = 0;
	char *old_pwd = getenv("OLDPWD");
	int count = 0;

	(void)env;

	if (tok_arr[1] != NULL)
	{
		if (tok_arr[1][0] == '-')
		{
			chdir(old_pwd);
		}
		else if (chdir(tok_arr[1]) == -1)
		{
			error_msg(2, count, argv[0], "can't cd to", tok_arr[1]);
		}
		return;
	}
	if (chdir(getcwd(_dir, size)) == -1)
	{
		error_msg(2, count, argv[0], "can't cd to", tok_arr[0]);
	}
	free(_dir);
}
/**
 * _env_handler - Builtin function prints the environment
 * @argv: Argument vector from command line
 * @env: Environment variables
 * @tok_arr: Array of user entry token
 */

void _env_handler(char **argv, char **env, char **tok_arr)
{
	int Q = 0, R = 0;

	(void)argv;
	(void)tok_arr;

	while (env[Q])
	{
		while (env[Q][R])
		{
			write(1, &env[Q][R], 1);
			R++;
		}
		R = 0;
		Q++;
		write(1, "\n", 1);
	}
}
