#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *nodes, *tmpe;
	unsigned long int t;

	for (t = 0; t < ht->size; t++)
	{
		if (ht->array[t] != NULL)
		{
			nodes = ht->array[t];
			while (nodes != NULL)
			{
				tmpe = nodes->next;
				free(nodes->key);
				free(nodes->value);
				free(nodes);
				nodes = tmpe;
			}
		}
	}
	free(head->array);
	free(head);
}

