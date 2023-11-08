#include "_shell.h"
/**
 * _strcat-This function appends the src string to
 * the dest string, overwriting the terminating null
 * byte (\0) at the end of dest, and then adds
 * a terminating null byte
 * @dest: destination string
 * @src: source string
 * Return:a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int Q;
	int R;

	for (Q = 0; dest[Q] != '\0'; Q++)
	{
	}
	for (R = 0; src[R] != '\0'; R++)
	{
		dest[Q] = src[R];
		Q++;
	}
	dest[Q] = '\0';
	return (dest);
}
/**
 * _memset-a function that fills memory with a constant byte.
 * @s: memory area
 * @b: constant byte
 * @n: total number of bytes
 * Return:s
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *ptr = s;

	while (n-- > 0)
	{
		*ptr++ = b;
	}
	return (s);
}
/**
 * _strncat-a function that concatenates two strings.
 * @dest: destination string
 * @src: source string
 * @n: maximum bytes to be used
 * The _strncat function is similar to the _strcat function, except that
 * it will use at most n bytes from src; and
 * src does not need to be null-terminated if it contains n or more bytes
 * Return:dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int Q;
	int R = 0;

	for (Q = 0; dest[Q] != '\0'; Q++)
	{
	}
	while (src[R] != '\0' && n > 0)
	{
		dest[Q] = src[R];
		Q++;
		R++;
		n--;

	}
	dest[Q] = '\0';
	return (dest);
}
/**
 * _memcpy-a function that copies memory area.
 * @dest: destination memory area
 * @src: source memory area
 * @n: size of bytes to be copied
 * Return:dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *ptr_dest = dest;
	char *ptr_src = src;

	while (n-- > 0)
	{
		*ptr_dest++ = *ptr_src++;
	}
	return (dest);
}
/**
  * _strchr-a function that locates a character in a string.
  * @s: string
  * @c: character to be located
  * Return:s if found or NULL if not found
  */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		else if (*(s + 1) == c)
		{
			return (s + 1);
		}
		s++;
	}
	return (s + 1);
}
