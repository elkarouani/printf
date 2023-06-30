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
