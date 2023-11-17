#include "_shell.h"
/**
 * _strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int Q, R;

	for (Q = 0; haystack[R] != '\0'; Q++)
	{
		for (R = 0; needle[R] != '\0'; R++)
		{
			if (haystack[Q + R] != needle[R])
				break;
		}
		if (!needle[R])
			return (&haystack[Q]);
	}
	return (NULL);
}

/**
 * _strlen - Returns the number of elements in a string
 * @s: String argument to be counted
 * Return: Always Sum (Success)
 */

int _strlen(char *s)
{
	int _length = 0;
	int Q;

	for (Q = 0; s[Q] != '\0'; Q++)
	{
		_length += 1;
	}

	return (_length);
}

/**
 * _strdup - copies the string given as parameter
 * @str: string to duplicate
 *
 * Return: pointer to the copied string (Success), NULL (Error)
 */

char *_strdup(char *str)
{
	char *copy;
	unsigned int Q, _len;

	Q = 0;
	_len = 0;

	if (str == NULL)
		return (NULL);

	while (str[_len])
		_len++;

	copy = malloc(sizeof(char) * (_len + 1));

	if (copy == NULL)
		return (NULL);

	while ((copy[Q] = str[Q]) != '\0')
		Q++;

	return (copy);
}
