#include "main.h"

/**
 *handle_specifier - Handles conversion specifiers for _printf function.
 *@specifier: The conversion specifier.
 *@args: The va_list containing the arguments.
 *
 *Return: The number of characters printed.
 */
int handle_specifier(char specifier, va_list args)
{
	unsigned int mask = 1;
	int count = 0;

	switch (specifier)
	{
		case 'c':
			count += putchar(va_arg(args, int));
			break;
		case 's':
			count += print_str(va_arg(args, char *));
			break;
		case '%':
			count += putchar('%');
			break;
		case 'd':
		case 'i':
			count += print_int(va_arg(args, int));
			break;
		case 'b':
			count += print_binary(va_arg(args, unsigned int), mask << (sizeof(unsigned int) *8 - 1));
			break;
		case 'u':
			count += print_unsigned(va_arg(args, unsigned int));
			break;
		case 'o':
			count += print_octal(va_arg(args, unsigned int));
			break;
		case 'x':
			count += print_hex(va_arg(args, unsigned int), 0);
			break;
		case 'X':
			count += print_hex_upper(va_arg(args, unsigned int), 0);
			break;
		case 'p':
			count += print_pointer(va_arg(args, void *));
			break;
		case 'r':
			count += print_str(va_arg(args, char *));
			break;
		default:
			count += putchar('%') + putchar(specifier);
	}

	return count;
}
