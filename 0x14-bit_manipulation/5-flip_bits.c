#include <stdio.h>
#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int g = n ^ m;
	unsigned int f = 0;

	while (g)
	{
		f += g & 1;
		g >>= 1;
	}

	return (f);
}
