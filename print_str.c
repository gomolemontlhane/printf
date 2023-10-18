#include "main.h"
#include <unistd.h>

/**
 *print_str - Prints a string to stdout.
 *@args: Arguments list.
 *
 *Return: Number of characters printed.
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		count += write(1, str, 1);
		++str;
	}

	return (count);
}
