#include "main.h"
#include <stdarg.h>
#include <stdio.h>

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
			switch (*ptr)
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
				default:
					count += putchar('%') + putchar(*ptr);
			}
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
 *putchar - Writes a character to stdout.
 *@c: The character to be written.
 *
 *Return: 1 (success), EOF (failure)
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
