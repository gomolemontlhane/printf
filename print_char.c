#include "main.h"
#include <unistd.h>

/**
 *print_char - Prints a character to stdout.
 *@args: Arguments list.
 *
 *Return: Number of characters printed.
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}
