#include "_shell.h"
/**
 * _strlen-a function that returns the length of a string.
 * @s: variable that represents the string
 * Return:void
 */
int _strlen(char *s)
{
	int Q = 0;

	while (s[Q] != '\0')
	{
		Q++;
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
char *_strncpy(char *dest, char *src, int n)
{
	int R = 0;

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
	int Q = 0;

	while (s1[Q] != '\0' || s2[Q] != '\0')
	{
		if (s1[Q] != s2[Q])
		{
			return (s1[Q] - s2[Q]);
			Q++;
		}
		Q++;
	}
	return (0);
}
/**
 * _strspn-a function that gets the length of a prefix substring.
 * @s: string
 * @accept: array to check size with
 * Return: number of bytes in the initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
	int Q, R, S;

	Q = 0;
	R = 0;

	while (s[Q] != '\0')
	{
		S = 0;
		while (accept[S] != '\0')
		{
			if (s[Q] == accept[S])
			{
				R++;
				break;
			}
			S++;
		}
		if (accept[S] == '\0')
		{
			break;
		}
		Q++;
	}
	return (R);
}
/**
 * _strpbrk-a function that searches a string
 * for any of a set of bytes.
 * @s: string to be searched
 * @accept: substring to be matched
 * Return: a pointer to the byte in s that matches
 * one of the bytes in accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	int Q, R;
	char *ptr;

	Q = 0;
	while (s[Q] != '\0')
	{
		R = 0;
		while (accept[R] != '\0')
		{
			if (accept[R] == s[Q])
			{
				ptr = &s[Q];
				return (ptr);
			}
			R++;
		}
		Q++;
	}
	return (0);
}
