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
	int len = 0, i;

	while (*(s + len))
		len++;

	i = len - 1;
	while (i >= 0) 
		_putchar(*(s + i--));

	return (len);
}

/**
 * _putrot13str - prints a string in rot13
 * @s: the string to be printed
 *
 * Return: number of characters printed
 */
int _putrot13str(char *s)
{
	int len, i;
	char brot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char arot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (len = 0; *(s + len); len++)
	{
		if (*(s + len) < 'A')
			_putchar(*(s + len));
		else if (*(s + len) > 'Z' && *(s + len) < 'a')
			_putchar(*(s + len));
		else if (*(s + len) > 'z')
			_putchar(*(s + len));
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (*(s + len) == brot13[i])
					_putchar(arot13[i]);
			}
		}
	}

	return (len);
}
