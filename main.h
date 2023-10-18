#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);
int print_int(va_list args);
int print_hex(va_list args);
int print_hex_upper(va_list args);
int print_binary(va_list args);
int print_percent(va_list args);
int print_octal(va_list args);
int print_pointer(va_list args);
int handle_specifier(char specifier, va_list args)

#endif /* MAIN_H */
