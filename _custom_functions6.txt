#include "_shell.h"
/**
 * _strstr-a function that locates a substring.
 * @haystack: string to searched
 * @needle: substring to be located
 * Return:a pointer to the beginning of the located
 * substring, or NULL if the substring is not found.
 */
char *_strstr(const char *haystack, const char *needle)
{
	while (*haystack != '\0')
	{
		const char *Q = haystack;
		const char *R = needle;

		while (*R != '\0' && *Q == *R)
		{
			Q++;
			R++;
		}
		if (*R == '\0')
		{
			return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
/**
 * _atoi-a function that convert a string to an integer.
 * @s: string to be converted
 * The number in the string can be preceded
 * by an infinite number of characters
 * You need to take into account all the -
 * and + signs before the number
 * If there are no numbers in the string, the function must return 0
 * You are not allowed to use long
 * You are not allowed to declare new variables of “type” array
 * You are not allowed to hard-code special values
 * We will use the -fsanitize=signed-integer-overflow
 * gcc flag to compile your code.
 * Return:The converted value
 */
int _atoi(const char *s)
{
	unsigned int number = 0;
	int plusorminus = 1;

	do {
		if (*s == '-')
		{
			plusorminus *= -1;
		}
		else if (*s >= '0' && *s <= '9')
		{
			number = (number * 10) + (*s - '0');
		}
		else if (number > 0)
		{
			break;
		}
	} while (*s++);
	return (number * plusorminus);
}
/**
 * _itoa-integer to ascii
 * @num: integer
 * @str: converted string
 * Return: converted string
 */
char *_itoa(int num, char *str)
{
	int Q = 0, _rem, _start, _end;
	int _isminus = 0;
	char temp;

	if (num == 0)
	{
		str[Q++] = '0';
		str[Q] = '\0';
		return (str);
	}
	if (num < 0)
	{
		_isminus = 1;
		num = -num;
	}
	while (num != 0)
	{
		_rem = num % 10;
		str[Q++] = _rem + '0';
		num = num / 10;
	}
	if (_isminus)
		str[Q++] = '-';
	str[Q] = '\0';
	_start = 0;
	_end = Q - 1;
	while (_start < _end)
	{
		temp = str[_start];
		str[_start] = str[_end];
		str[_end] = temp;
		_start++;
		_end--;
	}
	return (str);
}
/**
 * _strcatn-modified strcat
 * @dest: destination
 * @src: source
 * Return: new string
 */
char *_strcatn(char *dest, const char *src)
{
	size_t dest_len = _strlen(dest);
	size_t src_len = _strlen(src);
	char *_new_str = (char *)malloc(dest_len + src_len + 1);

	if (_new_str == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed in _strcatn\n");
		exit(EXIT_FAILURE);
	}
	_strcpy(_new_str, dest);
	_strcat(_new_str, src);
	return (_new_str);
}
/**
 * _calloc-a function that allocates memory for
 * an array, using malloc.
 * The _calloc function allocates memory for an array of
 * nmemb elements of size bytes each and returns a pointer
 * to the allocated memory.
 * The memory is set to zero
 * If nmemb or size is 0, then _calloc returns NULL
 * If malloc fails, then _calloc returns NULL
 * FYI: The standard library provides a different function:
 * calloc. Run man calloc to learn more.
 * @nmemb: elements of array
 * @size: size of bytes
 * Return:void
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	int overallsize, Q;
	void *p;
	char *ptr2;

	if (nmemb == 0 || size == 0)
		return (NULL);
	overallsize = nmemb * size;
	p = malloc(overallsize);

	if (p == NULL)
		return (NULL);
	ptr2 = p;
	Q = 0;
	while (overallsize > Q)
	{
		ptr2[Q] = 0;
		Q++;
	}
	return (p);
}
