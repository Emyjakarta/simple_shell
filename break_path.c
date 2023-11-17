#include "_shell.h"
/**
 * break_path - Splits the environment variable path
 * and returns a pointer to a dynamically allocated array
 * of strings - NULL terminated
 * @path_var: String of directories delimited by : to be split
 * Return: On Success array of strings char ** or NULL on fail
 */
char **break_path(char *path_var)
{
	char **tok_arr = NULL;
	int tok_num = 0, Q = 0;
	char *temp_path = _strdup(path_var), *temp_tok;

	if (path_var == NULL)
		return (NULL);

	if (temp_path != NULL)
	{
		temp_tok = strtok(temp_path, ":");
		while (temp_tok != NULL)
			tok_num++, temp_tok = strtok(NULL, ":");
	}
	tok_num++;
	tok_arr = malloc(sizeof(char *) * tok_num);
	if (tok_arr == NULL)
	{
		perror("Error allocating memory for tokens.");
		free(temp_path);
		return (NULL);
	}
	free(temp_path);
	temp_path = _strdup(path_var);
	temp_tok = strtok(temp_path, ":");
	tok_arr[Q] = _strdup(temp_tok);

	while (temp_tok != NULL)
		Q++, temp_tok = strtok(NULL, ":"),
			 tok_arr[Q] = _strdup(temp_tok);

	tok_arr[Q] = NULL;
	free(temp_path);
	return (tok_arr);
}
