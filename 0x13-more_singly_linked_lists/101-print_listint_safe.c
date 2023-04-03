#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current, *temp;

	current = head;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;

		/* move to next node */
		temp = current;
		current = current->next;

		/* check if we have already visited this node */
		if (temp <= current)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			printf("-> loop detected\n");
			exit(98);
		}
	}

	return (count);
}
