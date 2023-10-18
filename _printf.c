#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
 * handle_format_specifier - Handles the logic for a specific format specifier.
 * @specifier: The format specifier to handle.
 * @args: The va_list of arguments.
 *
 * Return: Number of characters printed.
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

/*Rest of the code remains unchanged */

/*Function prototypes */
int putchar(int c);
int print_str(char *str);
int print_int(int num);
