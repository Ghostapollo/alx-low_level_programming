#include <stdio.h>
#include "main.h"

/**
 * set_bit - the value of a bit to 1 at a given index
 * @n: the number to change
 * @index: index of the bit to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mine;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	mine = 1UL << index;

	*n |= mine;

	return (1);
}
