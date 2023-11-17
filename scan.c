#include "_shell.h"

/**
 * process_input - processes user input, splits into tokens and
 * returns an array of strings to the caller
 * @argv: Commandline argument for name of program
 * @mode: interative or not mode
 * Return: Array of strings
 */

char **process_entry(char **argv, int *mode)
{
	char *user_str = NULL;
	char **tok_arr = NULL;
	ssize_t str_read;
	size_t strBuffSize = 0;
	int Q = 0;

	signal(SIGINT, signal_handler);
	str_read = getline(&user_str, &strBuffSize, stdin);
	if (str_read < 0)
	{
		free(user_str);
		if (*mode == 1)
			write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	while (user_str[Q])
	{
		if (user_str[0] != '#' && user_str[Q] ==
				'#' && user_str[Q - 1] != ' ')
			break;

		if (user_str[Q] == '#')
			user_str[Q] = '\0';
		Q++;
	}
	tok_arr = break_user_entry(user_str);
	if (tok_arr == NULL)
	{
		free(user_str), _free_array_tokens(tok_arr);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	free(user_str);
	return (tok_arr);
}
