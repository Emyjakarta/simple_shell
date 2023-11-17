#include "_shell.h"
/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Return: a pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int Q, R;

	Q = 0;
	R = 0;

	while (dest[Q] != '\0')
		Q++;

	while (src[R] != '\0')
	{
		dest[Q] = src[R];
		Q++;
		R++;
	}

	dest[Q] = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strcpy - Returns the number of elements in a string
 * @dest: Destination
 * @src: Source
 * Return: dest (Success)
 */

char *_strcpy(char *dest, char *src)
{
	char *_dest_start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (_dest_start);
}
