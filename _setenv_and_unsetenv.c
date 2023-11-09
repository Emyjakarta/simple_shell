#include "_shell.h"
/**
 * _setenv-execute setenv command
 * @var: environment variable to set or modify
 * @value: value to set the environment variable
 * Return: void
 */
void _setenv(const char *var, const char *value)
{
	if (setenv(var, value, 1) != 0)
	{
		fprintf(stderr, "Failed to set environment variable\n");
	}
}
/**
 * _unsetenv-execute unsetenv command
 * @var: environment variable to unset
 * Return: void
 */
void _unsetenv(const char *var)
{
	if (unsetenv(var) != 0)
	{
		fprintf(stderr, "Failed to unset environment variable\n");
	}
}
