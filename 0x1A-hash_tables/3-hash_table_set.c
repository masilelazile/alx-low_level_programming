#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table to add or update
 * @key: string key
 * @value: value to be stored
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	unsigned long int hi_key;

	if (ht == NULL || key == NULL)
		return (0);

	if (node_update_check(ht, key, value))
		return (1);
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->next = NULL;
	if (value != NULL)
		new_node->value = strdup(value);
	hi_key = key_index((const unsigned char *)key, ht->size);

	if (ht->array[hi_key] == NULL)
		ht->array[hi_key] = new_node;
	else
	{
		new_node->next = ht->array[hi_key];
		ht->array[hi_key] = new_node;
	}

	return (1);
}

/**
 * node_update_check - checks a hash table for a key, updates if found.
 * @ht: the hash table to add or update
 * @key: string key
 * @value: value to be stored
 * Return: 1 if successful, 0 otherwise
 */
int node_update_check(hash_table_t *ht, const char *key, const char *value)
{
	char *temp;
	unsigned long int hi_key;
	hash_node_t *node;

	hi_key = key_index((const unsigned char *)key, ht->size);

	node = ht->array[hi_key];
	if (node == NULL)
		return (0);
	while (node != NULL)
	{
		if (strcmp(key, node->key) == 0)
		{
			temp = node->value;
			node->value = strdup(value);
			free(temp);
			return (1);
		}
		node = node->next;
	}
	return (0);
}
