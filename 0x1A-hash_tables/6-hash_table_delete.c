#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - deletes a hash table
 * @ht: the table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node, *temp;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			temp = node->next;
			free(node->key);
			if (node->value != NULL)
				free(node->value);
			free(node);
			node = temp;
		}
	}
	if (ht->array != NULL)
		free(ht->array);
	free(ht);
}
