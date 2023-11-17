#include "_shell.h"
/**
 * interactive_handler - Function that handles the interactive mode
 * @argv: Argument vector for program name or command line arg
 * @env: Environment variable received from main
 * @count: Keeps track of how many commands entered
 * @mode: Keeps track of the mode interactive or not
 * Return: Void
 */
void interactive_handler(char **argv, char **env, int *count, int *mode)
{
	char **tok_arr = process_entry(argv, mode), *in_path = NULL;

	if (tok_arr[0] == NULL || tok_arr == NULL)
	{
		free(tok_arr[0]), _free_array_tokens(tok_arr);
		return;
	}
	if (_builtins_handler(argv, env, tok_arr) == 1)
	{
		_free_array_tokens(tok_arr);
		return;
	}
	if (missing_path_handler(in_path, tok_arr, env,
							  mode, count, argv) == 1)
		return;
	if (access(tok_arr[0], F_OK) == -1)
	{
		if (PATH_handler(argv, env, tok_arr, count) == -1)
		{
			error_msg(2, *count, argv[0], tok_arr[0], "not found");
			_free_array_tokens(tok_arr);
			if (*mode != 1)
				exit(127);

			errno = 127;
			return;
		}
		_free_array_tokens(tok_arr);
		return;
	}
	full_Path_handler(tok_arr, env, argv, *mode);
}

/**
 * full_Path_handler - captures when the other path tests fails
 * @tok_arr: Array of tokenized user input
 * @env: Environment variables
 * @argv: Access program name from command line
 * @mode: Mode of interaction
 * Return: Void
 */
void full_Path_handler(char **tok_arr, char **env, char **argv, int mode)
{
	pid_t _pid_val;
	int execve_val, status = 0;

	(void)mode;
	_pid_val = fork();

	if (_pid_val == -1)
		_free_array_tokens(tok_arr), perror(argv[0]),
			exit(EXIT_FAILURE);
	else if (_pid_val == 0)
	{
		execve_val = execve(tok_arr[0], tok_arr, env);
		if (execve_val == -1)
			_free_array_tokens(tok_arr),
				perror(argv[0]), exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status), _free_array_tokens(tok_arr);
		errno = status;
	}
}
/**
 * missing_path_handler - Captures special case of check 27 types
 * @in_path: Checks if the command is in the path
 * @tok_arr: Array of tokenized user input
 * @env: Environment variables
 * @mode: Mode of interaction
 * @count: Command counts after each command entered
 * @argv: Access program name from command line
 * Return: Void
 */
int missing_path_handler(char *in_path, char **tok_arr,
						  char **env, int *mode, int *count, char **argv)
{
	in_path = locate_str(tok_arr[0], obtain_path(env));
	if (tok_arr[0][0] != '/' && tok_arr[0][0] != '.' &&
		tok_arr[1] == NULL &&
		access(tok_arr[0], F_OK) != -1 && in_path == NULL)
	{
		error_msg(2, *count, argv[0], tok_arr[0], "not found");
		_free_array_tokens(tok_arr);
		if (*mode != 1)
			exit(127);
		errno = 127; /*Error Status for when path not found*/
		return (1);	 /*Return for check in main function*/
	}
	else
		return (2);
}
