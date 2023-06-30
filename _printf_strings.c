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
 *
 * Return: length of the string
 */
int _putstr(char *s)
{
	int len = 0;

	while (*(s + len))
		_putchar(*(s + len++));

	return (len);
}

/**
 * _putptr - prints a pointer address
 * @p: pointer address to be printed
 *
 * Return: number of characters printed
 */
int _putptr(unsigned long int p)
{
	int count = 0;

	if (!p)
	{
		count += _putstr("(nil)");
		return (count);
	}

	count += _putstr("0x");
	count += _printf_hex(p, 0);

	return (count);
}

/**
 * _putrstr - prints a string in reverse
 * @s: the string to be printed
 *
 * Return: number of characters printed
 */
int _putrstr(char *s)
{
	int len = 0, i = 0;

	while (*(s + len))
		len++;

	while ((len - i) > -1)
		_putchar(*(s + len - i++));

	return (len);
}
