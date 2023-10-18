#include "main.h"
#include <unistd.h>

/**
 *print_percent - Prints a percent sign to stdout.
 *@args: Arguments list.
 *
 *Return: Always returns 1 (number of characters printed).
 */
int print_percent(va_list args)
{
	(void) args;	/* Unused parameter */
	write(1, "%", 1);
	return (1);
}
