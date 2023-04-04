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
	int loop_detected = 0;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;

		/* check if we have already visited this node */
		temp = head;

		for (size_t i = 0; i < count; i++)
		{
			if (temp == current)
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				printf("-> loop detected\n");
				loop_detected = 1;
				break;
			}
			temp = temp->next;
		}

		if (loop_detected)
			exit(98);

		current = current->next;
	}
	return (count);
}
