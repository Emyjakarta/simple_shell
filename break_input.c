#include "_shell.h"

/**
 * break_user_entry - Splits the user input into tokens
 * and returns a pointer to a dynamically allocated array
 * of strings - NULL terminated
 * @user_entry: String of user input delimited by " \n\t\r" to be plit
 * Return: On Success array of strings char ** or NULL on fail
 */

char **break_user_entry(char *user_entry)
{
	char **tok_arr = NULL;
	int tok_num = 0, Q = 0;
	char *temp_path = _strdup(user_entry), *temp_tok;
	char *delim = " \"\n\t\r";

	if (temp_path != NULL)
	{
		temp_tok = strtok(temp_path, delim);
		while (temp_tok != NULL)
			tok_num++, temp_tok = strtok(NULL, delim);
	}
	tok_num++;
	tok_arr = malloc(sizeof(char *) * tok_num);
	if (tok_arr == NULL)
	{
		perror("Error allocating memory for tokens.");
		free(temp_path), free(tok_arr);
		exit(EXIT_FAILURE);
	}

	free(temp_path);
	temp_path = _strdup(user_entry);
	temp_tok = strtok(temp_path, delim);
	tok_arr[Q] = _strdup(temp_tok);

	while (temp_tok != NULL)
	{
		Q++;
		temp_tok = strtok(NULL, delim);
		if (temp_tok != NULL)
			tok_arr[Q] = _strdup(temp_tok);
	}
	tok_arr[Q] = NULL;
	free(temp_path);
	return (tok_arr);
}
