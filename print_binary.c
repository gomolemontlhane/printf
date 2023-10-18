#include "main.h"
#include <stdio.h>

/**
 *print_binary - Prints an integer in binary to stdout.
 *@args: Arguments list.
 *
 *Return: Number of characters printed.
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[20];

	count = sprintf(buffer, "%b", n);	/* Assume %b is a valid format specifier*/

	if (count > 0)
		write(1, buffer, count);

	return (count);
}
