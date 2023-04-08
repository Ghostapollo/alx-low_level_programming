#include <stdio.h>
#include "main.h"

/**
 * get_bit - the value of a bit at a given index
 * @index: index of the bit
 * @n: number to check
 *
 * Return: the value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int cart;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	cart = 1UL << index;

	return (!!(n & cart));
}
