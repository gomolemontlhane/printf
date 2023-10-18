#include "main.h"

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
			count += handle_specifier(*ptr, args);
		}
		else
		{
			count += print_char(*ptr);
		}
	}

	va_end(args);
	return (count);
}
