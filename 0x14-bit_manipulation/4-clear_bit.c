#include <stdio.h>
#include "main.h"

/**
 * clear_bit - the value of a bit to 0 at a given index
 * @n: number to change
 * @index: index of the bit to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int d;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	d = ~(1UL << index);
	*n &= d;

	return (1);
}

