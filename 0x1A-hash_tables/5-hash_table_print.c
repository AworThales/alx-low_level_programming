#include "hash_tables.h"

/**
 * hash_table_print - Prints hash table.
 * @ht: A pointer to hash table to print.
 *
 * Description: Key/value pairs are printed in the order
 *              they appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *nodes;
	unsigned long int t;
	unsigned char comand_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (t = 0; t < ht->size; t++)
	{
		if (ht->array[t] != NULL)
		{
			if (comand_flag == 1)
				printf(", ");

			nodes = ht->array[t];
			while (nodes != NULL)
			{
				printf("'%s': '%s'", nodes->key, nodes->value);
				nodes = nodes->next;
				if (nodes != NULL)
					printf(", ");
			}
			comand_flag = 1;
		}
	}
	printf("}\n");
}
