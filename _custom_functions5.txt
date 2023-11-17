#include "_shell.h"
/**
 * _strncmp-compares two strings
 * @str1: first string
 * @str2: second string
 * @num: number of characters to be compared
 * Return: 0 if equal, -1 if less than the other or 1 if greater
 */
int _strncmp(const char *str1, const char *str2, size_t num)
{
	while (num > 0 && *str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return ((*str1 > *str2) ? 1 : -1);
		}
		str1++;
		str2++;
		num--;
	}
	if (num == 0)
		return (0);
	if (*str1 == '\0' && *str2 == '\0')
	{
		return (0);
	}
	else
	{
		return ((*str1 == '\0') ? -1 : 1);
	}
}
/**
 * _strtok-tokenize string
 * @str: string
 * @delim: delimiter
 * Return: Next token in the string based on delimiter
 */
char *_strtok(char *str, const char *delim)
{
	static char *_nexttoken;
	char *_token;

	if (str != NULL)
	{
		_nexttoken = str;
	}
	else if (_nexttoken == NULL || *_nexttoken == '\0')
		return (NULL);
	while (*_nexttoken != '\0' && _strchr((char *)delim, *_nexttoken) != NULL)
	{
		_nexttoken++;
	}
	if (*_nexttoken == '\0')
	{
		_nexttoken = NULL;
		return (NULL);
	}
	_token = _nexttoken;
	while (*_nexttoken != '\0' && _strchr((char *)delim, *_nexttoken) == NULL)
	{
		_nexttoken++;
	}
	if (*_nexttoken != '\0')
	{
		*_nexttoken = '\0';
		(*_nexttoken)++;
	}
	else
		_nexttoken = NULL;
	return (_token);
}
/**
 * _getline-reads a line from a file stream
 * @ptr_line: line to be read
 * @n: size of the buffer
 * @stream: file stream
 * Return: the number of characters read
 */
ssize_t _getline(char **ptr_line, size_t *n, FILE *stream)
{
	size_t _buffersize = *n, R = 0;
	int Q;
	char *_temp;

	if (*ptr_line == NULL || *n == 0)
	{
		*ptr_line = (char *)malloc(INITIAL_BUFFER_SIZE);
		if (*ptr_line == NULL)
			return (-1);
		_buffersize = INITIAL_BUFFER_SIZE;
		*n = _buffersize;
		while ((Q = fgetc(stream)) != EOF)
		{
			if (R + 1 >= _buffersize)
			{
				_buffersize *= 2;
				_temp = (char *)_realloc(*ptr_line, *n, _buffersize);
				if (_temp == NULL)
					return (-1);
				*ptr_line = _temp;
				*n = _buffersize;
			}
			(*ptr_line)[R++] = (char)Q;
			if (Q == '\n')
			{
				break;
			}
		}
		if (R == 0 || Q == EOF)
			return (-1);
		(*ptr_line)[R] = '\0';
		return (R);
	}
	return (0);
}
/**
 * _copy_memory-copy memory
 * @dest: destination
 * @src: source
 * @size: size to be copied
 * Return: dest
 */
void *_copy_memory(void *dest, const void *src, size_t size)
{
	unsigned char *ds = (unsigned char *)dest;
	const unsigned char *sc = (const unsigned char *)src;

	while (size--)
	{
		*ds++ = *sc++;
	}
	return (dest);
}
/**
 * _realloc-reallocates a memory block using malloc and free
 * @ptr: is a pointer to the previously allocated memory
 * @old_size: size of the allocated space for ptr
 * @new_size: size of the new memory block
 *
 * The contents will be copied to the newly allocated space,
 * in the range from the start of ptr up to the minimum
 * of the old and new sizes. If new_size > old_size, the “added”
 * memory should not be initialized. If new_size == old_size
 * do not do anything and return ptr. If ptr is NULL, then
 * the call is equivalent to malloc(new_size). If new_size is
 * equal to zero, and ptr is not NULL, then the call is
 * equivalent to free(ptr). Return NULL.
 * Don’t forget to free ptr when it makes sense
 *
 * Return:void
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *p1;
	size_t _copy_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == old_size)
		return (ptr);
	p1 = malloc(new_size);
	if (p1 == NULL)
	{
		free(ptr);
		return (NULL);
	}
	_copy_size = (old_size < new_size) ? old_size : new_size;
	_copy_memory(p1, ptr, _copy_size);
	free(ptr);
	return (p1);
}
