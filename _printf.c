#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the format to use
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int format_len = 0, current_count = 0, count = 0;
	char current_char, conversion_spec;
	va_list argv;

	va_start(argv, format);
	if (!format || (*format == '%' && !*(format + 1)))
		count = -1;
	while (format && *(format + format_len))
	{
		current_char = *(format + format_len);
		conversion_spec = *(format + format_len + 1);
		if (current_char != '%' || !conversion_spec)
		{
			if (current_char != '%')
			{
				_putchar(current_char);
				count++;
			}
			format_len++;
			continue;
		}
		current_count = _printf_with_spec(argv, conversion_spec);
		if (current_count == -1)
		{
			_putchar('%');
			count++;
		}
		else
		{
			count += current_count;
			format_len++;
		}
		format_len++;
	}
	va_end(argv);
	return (count);
}

/**
 * _printf_with_nums_spec - prints using nums spec
 * @argv: arguments list
 * @spec: conversion specifier used
 *
 * Return: printed characters count, -1 otherwise
 */
int _printf_with_nums_spec(va_list argv, char spec)
{
	int count = -1;

	switch (spec)
	{
		case 'd':
		case 'i':
			count = _printf_int(va_arg(argv, int));
			break;
		case 'u':
			count = _printf_uint(va_arg(argv, unsigned int));
			break;
		case 'o':
			count = _printf_octal(va_arg(argv, unsigned int));
			break;
		case 'x':
			count = _printf_hex(va_arg(argv, unsigned int), 0);
			break;
		case 'X':
			count = _printf_hex(va_arg(argv, unsigned int), 1);
			break;
		case 'b':
			count = _printf_binary(va_arg(argv, unsigned int));
			break;
	}

	return (count);
}

/**
 * _printf_with_strings_spec - prints with strings spec
 * @argv: arguments list
 * @spec: conversion specifier used
 *
 * Return: printed characters count
 */
int _printf_with_strings_spec(va_list argv, char spec)
{
	int count = -1;
	char *str;

	switch (spec)
	{
		case 'c':
			count = _putchar(va_arg(argv, int));
			break;
		case 's':
			str = va_arg(argv, char *);
			count = _putstr(!str ? "(null)" : str);
			break;
		case 'p':
			count = _putptr(va_arg(argv, unsigned long int));
			break;
		case '%':
			count = _putchar('%');
			break;
	}

	return (count);
}

/**
 * _printf_with_spec - prints using a conversion specifier
 * @argv: arguments list
 * @conversion_spec: conversion specifier used
 *
 * Return: printed characters count, -1 otherwise
 */
int _printf_with_spec(va_list argv, char conversion_spec)
{
	int count = -1;

	count = _printf_with_nums_spec(argv, conversion_spec);
	if (count == -1)
		count = _printf_with_strings_spec(argv, conversion_spec);

	return (count);
}
