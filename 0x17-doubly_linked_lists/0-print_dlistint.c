#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a double linked list.
 *
 * @h: Pointer to the head of the list.
 * Return: Number of nodes.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;
	
	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return count;
}
