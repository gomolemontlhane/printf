#include "main.h"
#include <stdio.h>

/**
 *print_pointer - Prints a pointer address to stdout.
 *@args: Arguments list.
 *
 *Return: Number of characters printed.
 */
int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	int count = 0;
	char buffer[20];

	count = sprintf(buffer, "%p", ptr);

	if (count > 0)
		write(1, buffer, count);

	return (count);
}
