#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the format to use
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int len = 0;
	int is_spec = 0;
	char current_char;
	char conversion_spec;
	va_list argv;

	va_start(argv, format);

	while (*(format + len))
	{
		current_char = *(format + len);
		if (current_char == '%' && *(format + len + 1))
		{
			conversion_spec = *(format + len + 1);
			is_spec = _printf_with_spec(argv, conversion_spec);

			if (!is_spec)
			{
				_putchar('%');
				len++;
				continue;
			}
			len++;
		}
		else
		{
			_putchar(current_char);
		}

		len++;
	}

	va_end(argv);
	return (--len);
}

/**
 * _printf_with_spec - prints using a conversion specifier
 * @argv: arguments list
 * @conversion_spec: conversion specifier used
 *
 * Return: 1 if conversion spec is correct, 0 otherwise
 */
int _printf_with_spec(va_list argv, char conversion_spec)
{
	switch (conversion_spec)
	{
		case 'd':
			_printf_int(va_arg(argv, int));
			break;
		case 'i':
			_printf_int(va_arg(argv, int));
			break;
		case 'u':
			_printf_uint(va_arg(argv, unsigned int));
			break;
		case 'o':
			_printf_octal(va_arg(argv, unsigned int));
			break;
		case 'x':
			_printf_hex(va_arg(argv, unsigned int), 0);
			break;
		case 'X':
			_printf_hex(va_arg(argv, unsigned int), 1);
			break;
		case 'c':
			_putchar(va_arg(argv, int));
			break;
		case 's':
			_putstr(va_arg(argv, char *));
			break;
		case 'p':
			_putptr(va_arg(argv, unsigned long int));
			break;
		case '%':
			_putchar('%');
			break;
		default:
			return (0);
	}

	return (1);
}
