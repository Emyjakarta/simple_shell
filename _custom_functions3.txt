#include "_shell.h"
/**
 * _strdup-a function that returns a pointer to a newly
 * allocated space in memory, which contains a copy of
 * the string given as a parameter.
 * @str: string
 * The _strdup() function returns a pointer to a new string which is
 * a duplicate of the string str. Memory for the new string is obtained
 * with malloc, and can be freed with free.
 * Return:NULL if str = NULL
 * On success, the _strdup function returns a pointer to the duplicated
 * string. It returns NULL if insufficient memory was available
 * FYI: The standard library provides a similar function:
 * strdup. Run man strdup to learn more.
 */
char *_strdup(const char *str)
{
	size_t _len = _strlen(str);
	char *copy = (char *)malloc(_len + 1);

	if (copy != NULL)
	{
		_strcpy(copy, str);
	}
	return (copy);
}
/**
 * argstostr-a function that concatenates all the
 * arguments of your program
 * @ac: number of arguments
 * @av: array of argument strings
 * Returns NULL if ac == 0 or av == NULL
 * Returns a pointer to a new string, or NULL if it fails
 * Each argument should be followed by a \n in the new string
 * Return:pointer to the new string
 */
char *argstostr(int ac, char **av)
{
	int Q = 0, overall_length = 0, length_av = 0, post = 0;
	char *new_string;

	if (ac == 0 || av == NULL)
		return (NULL);
	while (ac > Q)
	{
		length_av = 0;
		while (av[Q][length_av] != '\0')
		{
			length_av++;
		}
		overall_length += length_av + 1;
		Q++;
	}
	new_string = malloc(overall_length + 1);
	if (new_string == NULL)
	{
		return (NULL);
	}
	Q = 0;
	post = 0;
	while (ac > Q)
	{
		length_av = 0;
		while (av[Q][length_av] != '\0')
		{
			new_string[post++] = av[Q][length_av];
			length_av++;
		}
		new_string[post++] = '\n';
		Q++;
	}
	return (new_string);
}
/**
 * wordcount-count words
 * @str: string
 * Return:cnt
 */
int wordcount(char *str)
{
	int cnt = 0, word = 0;

	if (str == NULL || *str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
		{
			word = 0;
		}
		else if (!word)
		{
			cnt++;
			word = 1;
		}
		str++;
	}
	return (cnt);
}
/**
 * wordextract-extract words
 * @start: start position of word in input string
 * @length: length of word
 * Return:word
 */
char *wordextract(char *start, int length)
{
	char *word = (char *)malloc((length + 1) * (sizeof(char)));

	if (word == NULL)
	{
		return (NULL);
	}
	_strncpy(word, start, length);
	word[length] = '\0';
	return (word);
}
/**
 * wordpopulate-populate words
 * @words: array of pointers to words that will be populated in the function
 * @str: represents the input string
 * Return:words
 */
char **wordpopulate(char **words, char *str)
{
	int i, wrdcnt = 0, wrdlen = 0;

	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
		{
			if (wrdlen > 0)
			{
				words[wrdcnt] = wordextract(str - wrdlen, wrdlen);
				if (words[wrdcnt] == NULL)
				{
					for (i = 0; i < wrdcnt; i++)
						free(words[i]);
					free(words);
					return (NULL);
				}
				wrdcnt++;
				wrdlen = 0;
			}
		}
		else
			wrdlen++;
		str++;
	}
	if (wrdlen > 0)
	{
		words[wrdcnt] = wordextract(str - wrdlen, wrdlen);
		if (words[wrdcnt] == NULL)
		{
			for (i = 0; i <= wrdcnt; i++)
				free(words[i]);
			free(words);
			return (NULL);
		}
		wrdcnt++;
	}
	words[wrdcnt] = NULL;
	return (words);
}
