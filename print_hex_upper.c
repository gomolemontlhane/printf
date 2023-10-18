#include "main.h"
#include <stdio.h>

/**
 *print_hex_upper - Prints an integer in uppercase hexadecimal to stdout.
 *@args: Arguments list.
 *
 *Return: Number of characters printed.
 */
int print_hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[20];

	count = sprintf(buffer, "%X", n);

	if (count > 0)
		write(1, buffer, count);

	return (count);
}
