#include <stdio.h>
#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: number to print
 */
void print_binary(unsigned long int n)
{
	unsigned long int cover = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int sign = 0;

	while (cover)
	{
		if (n & cover)
		{
			sign = 1;
			putchar('1');
		}
		else if (sign)
		{
			putchar('0');
		}
		cover >>= 1;
	}

	if (!sign)
	{
		putchar('0');
	}
}
