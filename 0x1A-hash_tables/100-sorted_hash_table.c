#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"


static void sorted_insert(shash_node_t **shead, shash_node_t *new_node);

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new;

	if (size == 0)
		return (NULL);

	new = malloc(sizeof(shash_table_t));
	if (new == NULL)
		return (NULL);
	new->size = size;

	new->array = calloc(sizeof(shash_node_t *), size);
	if (new->array == NULL)
	{
		free(new);
		return (NULL);
	}

	new->shead = NULL;
	new->stail = NULL;

	return (new);
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node;
	unsigned long int hi_key;

	if (ht == NULL || key == NULL)
		return (0);

	if (node_update_check(ht, key, value))
		return (1);
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->next = NULL;
	new_node->sprev = NULL;
	new_node->snext = NULL;
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

	sorted_insert(&ht->shead, new_node);

	return (1);
}

static void sorted_insert(shash_node_t **shead, shash_node_t *new_node)
{
	shash_node_t *current;

	if (*shead == NULL)
	{
		*shead = new_node;
		return;
	}

	current = *shead;
	while (current != NULL)
	{
		if (strcmp(new_node->key, current->key) < 0)
		{
			new_node->snext = current;
			new_node->sprev = current->sprev;
			if (current->sprev != NULL)
				current->sprev->snext = new_node;
			else
				*shead = new_node;
			current->sprev = new_node;
			return;
		}
		if (current->snext == NULL)
		{
			new_node->sprev = current;
			current->snext = new_node;
			return;
		}
		current = current->snext;
	}
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *temp;
	unsigned long int hi_key;

	if (ht == NULL || key == NULL)
		return (NULL);
	hi_key = key_index((unsigned char *)key, ht->size);

	temp = ht->array[hi_key];
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
	{
		return (temp->value);
	}
		temp = temp->next;
	}
	return (NULL);
	}

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	unsigned int count = 0;
	if (ht == NULL)
	{
		return;
	}

	printf("{");
	node = ht->shead;
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
		count++;
	}
	printf("}\n");
}

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	unsigned int count = 0;
	if (ht == NULL)
	{
		return;
	}

	printf("{");
	node = ht->stail;
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
		count++;
	}
	printf("}\n");
}

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp;
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
