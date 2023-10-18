#include "main.h"
#include <stdio.h>

/**
 *print_unsigned - Prints an unsigned integer to stdout.
 *@args: Arguments list.
 *
 *Return: Number of characters printed.
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[20];

	count = sprintf(buffer, "%u", n);

	if (count > 0)
		write(1, buffer, count);

	return (count);
}
