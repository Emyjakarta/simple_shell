#include "_shell.h"

/**
 * main - Simple Shell.
 * @argc: Number of arguments
 * @argv: Array of null terminated strings
 * @env: Environment variables
 * Return: 0
 */

int main(int argc, char **argv, char **env)
{
	int mode = 0;

	int count_com = 1;
	(void)argc;

	if (isatty(0) == 1)
		mode = 1;

	errno = 0;

	while (1)
	{
		if (mode == 1)
		{
			_show_prompt();
		}

		interactive_handler(argv, env, &count_com, &mode);
		count_com++;
	}

	return (errno);
}

/**
 * _free_array_tokens - frees an array of strings
 * @arr_tok: Argument pointer to grid to be freed
 * Return: Void;
 */

void _free_array_tokens(char **arr_tok)
{
	int i = 0;

	while (arr_tok[i] != NULL)
	{
		free(arr_tok[i]);
		i++;
	}

	free(arr_tok);
}
