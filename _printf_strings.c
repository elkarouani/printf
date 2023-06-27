#include "main.h"

/**
 * _putchar - write the character c to stdout
 * @c: the character to print
 *
 * Return: On success 1, On error -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - prints a string
 * @s: the string to be printed
 */
void _putstr(char *s)
{
	int len = 0;

	while (*(s + len))
		_putchar(*(s + len++));
}

/**
 * _putptr - prints a pointer address
 * @p: pointer address to be printed
 */
void _putptr(unsigned long int p)
{
	_putstr("0x");
	_printf_hex(p, 0);
}
