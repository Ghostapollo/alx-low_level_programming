#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: Pointer to the pointer to the head node.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *tmp;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL)
	{
		tmp = (*h)->next;
		free(*h);
		count++;
		if (tmp >= *h)
		{
			*h = NULL;
			break;
		}
		else
			*h = tmp;
	}

	return (count);
}
