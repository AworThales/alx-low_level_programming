#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int t;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (t = 0; t < size; t++)
		ht->array[t] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmps;
	char *value_copying;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copying = strdup(value);
	if (value_copying == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	tmps = ht->shead;
	while (tmps)
	{
		if (strcmp(tmps->key, key) == 0)
		{
			free(tmps->value);
			tmps->value = value_copying;
			return (1);
		}
		tmps = tmps->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_copying);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_copying);
		free(new);
		return (0);
	}
	new->value = value_copying;
	new->next = ht->array[idx];
	ht->array[idx] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		tmps = ht->shead;
		while (tmps->snext != NULL && strcmp(tmps->snext->key, key) < 0)
			tmps = tmps->snext;
		new->sprev = tmps;
		new->snext = tmps->snext;
		if (tmps->snext == NULL)
			ht->stail = new;
		else
			tmps->snext->sprev = new;
		tmps->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with
 *                   a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *nodes;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);

	nodes = ht->shead;
	while (nodes != NULL && strcmp(nodes->key, key) != 0)
		nodes = nodes->snext;

	return ((nodes == NULL) ? NULL : nodes->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *nodes;

	if (ht == NULL)
		return;

	nodes = ht->shead;
	printf("{");
	while (nodes != NULL)
	{
		printf("'%s': '%s'", nodes->key, nodes->value);
		nodes = nodes->snext;
		if (nodes != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *nodes;

	if (ht == NULL)
		return;

	nodes = ht->stail;
	printf("{");
	while (nodes != NULL)
	{
		printf("'%s': '%s'", nodes->key, nodes->value);
		nodes = nodes->sprev;
		if (nodes != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *nodes, *tmps;

	if (ht == NULL)
		return;

	nodes = ht->shead;
	while (nodes)
	{
		tmps = nodes->snext;
		free(nodes->key);
		free(nodes->value);
		free(nodes);
		nodes = tmps;
	}

	free(head->array);
	free(head);
}
