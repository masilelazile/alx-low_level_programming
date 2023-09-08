#include "hash_tables.h"
#include <stdio.h>

/**
 * key_index - gives you the index of a key
 * @key: string to be indexed
 * @size: the size of the hash table
 * Return: ul int index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index;

	index = hash_djb2(key);
	index = index % size;

	return (index);
}
