#include "_shell.h"
/**
 * strtow-a function that splits a string into words
 * The function returns a pointer to an array of strings (words)
 * @str: string
 * Each element of this array should contain a single word, null-terminated
 * The last element of the returned array should be NULL
 * Words are separated by spaces
 * Returns NULL if str == NULL or str == ""
 * If your function fails, it should return NULL
 * Return:pointer to an array of strings
 */
char **strtow(char *str)
{
	int nword, space_only;
	char **wrds;

	if (str == NULL || *str == '\0')
		return (NULL);
	space_only = 1;
	while (*str)
	{
		if (*str != ' ')
		{
			space_only = 0;
			break;
		}
		str++;
	}
	if (space_only)
	{
		return (NULL);
	}
	nword = wordcount(str);
	wrds = (char **)malloc((nword + 1) * sizeof(char *));
	if (wrds == NULL)
		return (NULL);
	wrds = wordpopulate(wrds, str);
	return (wrds);
}
/**
 * freewords-free memory
 * @words: memory to be freed
 * Return:void
 */
void freewords(char **words)
{
	int i;

	if (words == NULL)
		return;
	for (i = 0; words[i] != NULL; i++)
	{
		free(words[i]);
	}
	free(words);
}
/**
 * str_concat-a function that concatenates two strings
 * @s1: destination string
 * @s2: source string
 * The returned pointer should point to a newly allocated space
 * in memory which contains the contents of s1, followed by
 * the contents of s2, and null terminated
 * if NULL is passed, treat it as an empty string
 * The function should return NULL on failure
 * Return:pointer to the new string
 */
char *str_concat(char *s1, char *s2)
{
	char *ptr;
	int length, Q = 0, R = 0, S = 0, T = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[Q] != '\0')
	{
		Q++;
	}
	while (s2[R] != '\0')
	{
		R++;
	}
	length = Q + R + 1;
	ptr = malloc(length);
	if (ptr == NULL)
		return (NULL);
	while (S < Q)
	{
		ptr[S] = s1[S];
		S++;
	}
	while (T < R)
	{
		ptr[S] = s2[T];
		S++;
		T++;
	}
	ptr[S] = '\0';
	return (ptr);
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
