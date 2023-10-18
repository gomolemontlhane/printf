#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/*Function prototypes */
int handle_format_specifier(char specifier, va_list args);

/**
 *_printf - Produces output according to a format.
 *@format: Format string containing zero or more directives.
 *
 *Return: Number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;

	va_start(args, format);

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1); /*Invalid format */

	for (ptr = format; *ptr; ++ptr)
	{
		if (*ptr == '%')
		{ ++ptr; /*Move to the character after '%' */
			if (*ptr == '\0')
				break; /*Invalid format */
			count += handle_format_specifier(*ptr, args);
		}
		else
		{
			count += putchar(*ptr);
		}
	}

	va_end(args);
	return (count);
}

/**
 *handle_format_specifier - Handles the logic for a specific format specifier.
 *@specifier: The format specifier to handle.
 *@args: The va_list of arguments.
 *
 *Return: Number of characters printed.
 */
int handle_format_specifier(char specifier, va_list args)
{
	int count = 0;

	switch (specifier)
	{
		case 'c':
			count += putchar(va_arg(args, int));
			break;
		case 's':
			count += print_str(va_arg(args, char *));
			break;
		case 'd':
		case 'i':
			count += print_int(va_arg(args, int));
			break;
		case '%':
			count += putchar('%');
			break;
		default:
			count += putchar('%') + putchar(specifier);
	}

	return (count);
}

/**
 *putchar - Writes a character to stdout.
 *@c: The character to be written.
 *
 *Return: The character written (success), EOF (failure).
 */
int putchar(int c)
{
	return (write(1, &c, 1));
}

/**
 *print_str - Writes a string to stdout.
 *@str: The string to be written.
 *
 *Return: Number of characters written.
 */
int print_str(char *str)
{
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		count += putchar(*str);
		++str;
	}

	return (count);
}

/**
 *print_int - Writes an integer to stdout.
 *@num: The integer to be written.
 *
 *Return: Number of characters written.
 */
int print_int(int num)
{
	int count = 0;
	int temp, digits;

	if (num < 0)
	{
		count += putchar('-');
		num = -num;
	}

	temp = num;
	digits = 1;
	while (temp /= 10)
		digits *= 10;

	while (digits)
	{
		count += putchar(num / digits + '0');
		num %= digits;
		digits /= 10;
	}

	return (count);
}
