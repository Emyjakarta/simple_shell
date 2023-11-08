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
			return (*str1 > *str2) ? 1 : -1;
		}
		str1++;
		str2++;
		if (num > 0)
		{
			if (*str1 == '\0' && *str2 == '\0')
			{
				return (0);
			}
			else
			{
				return (*str1 == '\0') ? -1 : 1;
			}
		}
		return (0);
	}
}
