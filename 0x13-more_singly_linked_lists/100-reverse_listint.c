#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current, *next;

	current = *head;
	*head = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = *head;
		*head = current;
		current = next;
	}

	return (*head);
}
