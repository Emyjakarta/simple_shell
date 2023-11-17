#include "_shell.h"
/**
 * _strtokm-tokenize string
 * @str: string
 * @delim: delimiter
 * Return: Next token in the string based on delimiter
 */
char *_strtokm(char *str)
{
	static char *_nexttoken;
	char *_tokenstart, *token_copy;

	if (str != NULL)
	{
		_nexttoken = str;
	}
	else if (_nexttoken == NULL || *_nexttoken == '\0')
		return (NULL);
	while (*_nexttoken != '\0' && *_nexttoken == ';')
	{
		_nexttoken++;
	}
	if (*_nexttoken == '\0')
	{
		return (NULL);
	}
	_tokenstart = _nexttoken;
	while (*_nexttoken != '\0' && *_nexttoken != ';')
	{
		_nexttoken++;
	}
	if (*_nexttoken != '\0')
	{
		token_copy = (char *)malloc((_nexttoken - _tokenstart + 1) * sizeof(char));
		if (token_copy == NULL)
			return NULL;
		memcpy(token_copy, _tokenstart, _nexttoken - _tokenstart);
		token_copy[_nexttoken - _tokenstart] = '\0';
		while (*_nexttoken != '\0' && *_nexttoken == ';')
		{
			_nexttoken++;
		}
	}
	else
	{
		token_copy = (char *)malloc((_nexttoken - _tokenstart + 1) * sizeof(char));
		if (token_copy == NULL)
			return NULL;
		memcpy(token_copy, _tokenstart, _nexttoken - _tokenstart);
		token_copy[_nexttoken - _tokenstart] = '\0';
	}
	return (token_copy);
}
