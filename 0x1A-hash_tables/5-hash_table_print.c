#include "hash_tables.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * hash_table_print - prints a hash table
 * @ht: the table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i, count, total;

	if (ht == NULL)
	{
		return;
	}
	printf("{");
	count = 0;
	total = hash_table_node_count(ht);
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			printf("'%s': '%s'", node->key, node->value);
			count++;
			node = node->next;
			if (count < total)
				printf(", ");
		}
	}
	printf("}\n");
}

/**
 * hash_table_node_count - counts the nodes in a hash table
 * @ht: the table
 * Return: number of nodes.
 */
unsigned long int hash_table_node_count(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i, count;

	if (ht == NULL)
		return (0);

	count = 0;
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			count++;
			node = node->next;
		}
	}
	return (count);
}
