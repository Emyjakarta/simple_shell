#include "_shell.h"
/**
 * _strstr-a function that locates a substring.
 * @haystack: string to searched
 * @needle: substring to be located
 * Return:a pointer to the beginning of the located
 * substring, or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	if (*needle == '\0')
	{
		return (haystack);
	}
	while (*haystack != '\0')
	{
		char *Q = haystack;
		char *R = needle;

		while (*R != '\0' && *Q == *R)
		{
			Q++;
			R++;
		}
		if (*R == '\0')
		{
			return (haystack);
		}
		haystack++;
	}
	return (NULL);
}
/**
 * *_strcpy-a function that copies the string
 * pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest.
 * @dest: first variable of string
 * @src: second variable of string
 * Return:the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *dest1 = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest1);
}
