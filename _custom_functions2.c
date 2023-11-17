#include "_shell.h"
/**
 * _strlen-a function that returns the length of a string.
 * @s: variable that represents the string
 * Return:void
 */
int _strlen(const char *s)
{
	size_t Q = 0;

	while (*s != '\0')
	{
		Q++;
		s++;
	}
	return (Q);
}
/**
 * _strncpy-a function that copies a string
 * Your function should work exactly like strncpy
 * @dest: destination string
 * @src: source string
 * @n: maximum bytes that can be contained in the string
 * Return:dest
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t R = 0;

	while (src[R] != '\0' && R < n)
	{
		dest[R] = src[R];
		R++;
	}
	while (n > R)
	{
		dest[R] = '\0';
		R++;
	}
	return (dest);
}
/**
 * _strcmp-a function that compares two strings.
 * @s1: first string variable
 * @s2: secod string variable
 * Your function should work exactly like strcmp
 * Return:Their difference and zero at the end
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}
/**
 * _strspn-a function that gets the length of a prefix substring.
 * @s: string
 * @accept: array to check size with
 * Return: number of bytes in the initial segment of s
 */
size_t _strspn(const char *s, const char *accept)
{
	size_t Q = 0;

	while (*s != '\0' && _strchr(accept, *s) != NULL)
	{
		Q++;
		s++;
	}
	return (Q);
}
/**
 * _strpbrk-a function that searches a string
 * for any of a set of bytes.
 * @s: string to be searched
 * @accept: substring to be matched
 * Return: a pointer to the byte in s that matches
 * one of the bytes in accept, or NULL if no such byte is found
 */
char *_strpbrk(const char *s, const char *accept)
{
	while (*s != '\0')
	{
		if (_strchr(accept, *s) != NULL)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
