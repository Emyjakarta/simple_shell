#include "_shell.h"
/**
 * _setenv-execute setenv command
 * @var: environment variable to set or modify
 * @value: value to set the environment variable
 * Return: void
 */
void _setenv(const char *var, const char *value)
{
	if (var == NULL || value == NULL)
	{
		fprintf(stderr, "Error: var or value is NULL\n");
		return;
	}
	if (setenv(var, value, 1) == -1)
	{
		perror("Error: Failed to set environment variable\n");
	}
}
/**
 * _unsetenv-execute unsetenv command
 * @var: environment variable to unset
 * Return: void
 */
void _unsetenv(const char *var)
{
	if (var == NULL)
	{
		fprintf(stderr, "Error: var is NULL\n");
		return;
	}
	if (unsetenv(var) != 0)
	{
		fprintf(stderr, "Failed to unset environment variable\n");
	}
}
