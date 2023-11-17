#include "_shell.h"

/**
 * locate_str - finds if a string exists in the path
 * @com: Command string to be searched in the path
 * @_path: retrieved path variable
 * Return: Pointer to string if it it exists or NULL otherwise
 */

char *locate_str(char *com, char *_path)
{
	char *_result = NULL;

	if (_path != NULL)
		_result = _strstr(_path, com);
	return (_result);
}
