#include "main.h"

/**
 * _printf_int - prints an integer
 * @n: the integer to be printed
 */
void _printf_int(int n)
{
	unsigned int n1;

	if (n < 0)
		_putchar('-');
	n1 = n < 0 ? -n : n;

	if (n1 / 10)
		_printf_int(n1 / 10);
	_putchar((n1 % 10) + 48);
}

/**
 * _printf_uint - prints an unsigned integer
 * @n: the integer to be printed
 */
void _printf_uint(unsigned int n)
{
	if (n / 10)
		_printf_uint(n / 10);
	_putchar((n % 10) + 48);
}

/**
 * _printf_octal - prints an octal based integer
 * @n: the number to be printed
 */
void _printf_octal(unsigned int n)
{
	if (n / 8)
		_printf_octal(n / 8);
	_putchar((n % 8) + 48);
}

/**
 * _printf_hex - prints a hexadecimal number
 * @n: the number to be printed
 * @u: is letters uppercased
 */
void _printf_hex(unsigned long int n, short int u)
{
	if (n / 16)
		_printf_hex(n / 16, u);

	if ((n % 16) < 10)
		_putchar((n % 16) + 48);
	else
		_putchar((u ? 'A' : 'a') + ((n % 16) - 10));
}
