#include "hash_tables.h"

/**
 * key_index - Get index at which the  key/value
 *      pair should be stored in the array of a hash table.
 * @key: The key to get the index of.
 * @size: The size of array of hash table.
 *
 * Return: The index of key.
 * Description: Uses the djb2 algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
