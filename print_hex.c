#include "main.h"
#include <stdio.h>

/**
 *print_hex - Prints an integer in hexadecimal to stdout.
 *@args: Arguments list.
 *
 *Return: Number of characters printed.
 */
int print_hex(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[20];

	count = sprintf(buffer, "%x", n);

	if (count > 0)
		write(1, buffer, count);

	return (count);
}
