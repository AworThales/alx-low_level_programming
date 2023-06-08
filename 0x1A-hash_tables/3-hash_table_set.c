#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in hash table.
 * @ht: A pointer to hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	char *value_copying;
	unsigned long int idx, t;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copying = strdup(value);
	if (value_copying == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	for (t = idx; ht->array[t]; t++)
	{
		if (strcmp(ht->array[t]->key, key) == 0)
		{
			free(ht->array[t]->value);
			ht->array[t]->value = value_copying;
			return (1);
		}
	}

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(value_copying);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = value_copying;
	new->next = ht->array[idx];
	ht->array[idx] = new;

	return (1);
}
