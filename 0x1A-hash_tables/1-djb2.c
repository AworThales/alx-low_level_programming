#include "hash_tables.h"

/**
 * hash_djb2 - Hash function implementing the djb2 algorithm.
 * @str: The string to hashed.
 *
 * Return: The calculated hashed.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hashed;
	int t;

	hashed = 5381;
	while ((t = *str++))
		hashed = ((hashed << 5) + hashed) + t; /* hashed * 33 + t */

	return (hashed);
}
