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
		count++;

		/* check if we have already visited this node */
		temp = head;
		size_t i;

		for (i = 0; i < count - 1; i++)
		{
			if (temp == current)
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				printf("-> loop detected\n");
				exit(98);
			}
			temp = temp->next;
		}

		/* move to next node */
		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;
	}

	return (count);
}

