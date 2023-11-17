#include "_shell.h"

/**
 * error_msg - Printing custom error message to stderr
 * @_fd: File descriptor
 * @num: Numbeer of commands written so far
 * @s1: First string - name of program
 * @s2: Name of command
 * @s3: custom message to be printed
 * Return: Void
 */

void error_msg(int _fd, int num, char *s1, char *s2, char *s3)
{
	char _num_stat;
	int temp = num;

	while (*s1)
	{
		write(_fd, &(*s1), 1), s1++;
	}
	write(_fd, ": ", 2);

	if (num < 10)
	{
		_num_stat = num + '0';
		write(_fd, &(_num_stat), 1);
	}
	else
	{
		_num_stat = (num / 10) + '0';
		write(_fd, &(_num_stat), 1);
		_num_stat = (temp % 10) + '0';
		write(_fd, &(_num_stat), 1);
	}
	write(_fd, ": ", 2);

	while (*s2)
		write(_fd, &(*s2), 1), s2++;

	write(2, ": ", 2);

	while (*s3)
		write(_fd, &(*s3), 1), s3++;

	write(_fd, "\n", 1);
}
