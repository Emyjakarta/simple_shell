#include "_shell.h"

/**
 * signal_handler - Handles the CTRL + C signal
 * @sign: signal
 * Return: Returns Void
 */

void signal_handler(int sign)
{
	(void)sign;
	write(1, "\n", 1);
	write(1, "Emyjakarta$ ", 12);
}
