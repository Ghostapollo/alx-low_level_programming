#include <stdio.h>
#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Returns: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int task = 1;
	char *r = (char *)&task;

	if (*r)
		return (1);
	else
		return (0);
}
