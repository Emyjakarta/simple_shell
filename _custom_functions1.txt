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
char *_strcat(char *dest, const char *src)
{
	size_t dest_len = _strlen(dest);
	char *_new_str = dest + dest_len;

	while (*src != '\0')
	{
		*_new_str++ = *src++;
	}
	*_new_str = '\0';
	return (dest);
}
/**
 * _memset-a function that fills memory with a constant byte.
 * @s: memory area
 * @c: constant byte
 * @n: total number of bytes
 * Return:s
 */
void *_memset(void *s, int c, size_t n)
{
	unsigned char *ptr = s;

	while (n-- > 0)
	{
		*ptr++ = (unsigned char)c;
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
char *_strncat(char *dest, const char *src, size_t n)
{
	char *ptr = dest + _strlen(dest);

	while (*src != '\0' && n-- > 0)
	{
		*ptr++ = *src++;

	}
	*ptr = '\0';
	return (dest);
}
/**
 * _memcpy-a function that copies memory area.
 * @dest: destination memory area
 * @src: source memory area
 * @n: size of bytes to be copied
 * Return:dest
 */
char *_memcpy(void *dest, const void *src, size_t n)
{
	char *ptr_dest = dest;
	const char *ptr_src = src;

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
char *_strchr(const char *s, int c)
{
	while (*s != '\0' && *s == c)
	{
		return ((char *)s);
		s++;
	}
	return (NULL);
}
