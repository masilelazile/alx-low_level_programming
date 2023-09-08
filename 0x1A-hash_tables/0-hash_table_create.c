#include "hash_tables.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * hash_table_create - creates a hash table
 * @size: size of the array
 * Return: pointer to the newly created array.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new;

	if (size == 0)
		return (NULL);

	new = malloc(sizeof(hash_table_t));
	if (new == NULL)
		return (NULL);
	new->size = size;

	new->array = calloc(sizeof(hash_node_t *), size);
	if (new->array == NULL)
	{
		free(new);
		return (NULL);
	}

	return (new);
}
