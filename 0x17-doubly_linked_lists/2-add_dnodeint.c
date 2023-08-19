#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a list.
 * @head: pointer to the beginning of a listint_t list
 * @n: integer data
 *
 * Return: pointer to the new created node.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *head;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	h = *head;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;
	}

	new->next = head;

	if (h != NULL)
		head->prev = new;

	*head = new;

	return (new);
}
