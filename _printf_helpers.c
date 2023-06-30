#include "main.h"

/**
 * count_hex - count possible chars that can be printed as hex
 * @n: the number to be printed
 *
 * Return: the chars count
 */
int count_hex(unsigned long int n)
{
	int digits = 1;
	unsigned long int n1 = n;

	while (n1 / 16)
	{
		digits++;
		n1 /= 16;
	}

	return (digits);
}

/**
 * is_flag - checks if the passed spec is flag
 * @spec: the spec to check
 *
 * Return: 0 ro 1
 */
int is_flag(char spec)
{
	if (spec == '+')
		return (1);
	if (spec == ' ')
		return (1);
	if (spec == '#')
		return (1);

	return (0);
}
