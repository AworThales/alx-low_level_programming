#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int d;
	char *ptr;

	d = 1;
	ptr = (char *) &d;

	return ((int)*ptr);
}
