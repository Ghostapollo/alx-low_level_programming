#include "lists.h"
#include <stddef.h>
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
	const listint_t *tortoise, *hare;

	tortoise = hare = head;

	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		/* If the hare catches up with the tortoise, there's a loop */
		if (tortoise == hare)
		{
			printf("-> [%p] %d\n", (void *)tortoise, tortoise->n);
			printf("-> loop detected\n");
			exit(98);
		}

		/* print current node */
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		count++;
	}

	/* print the last node and return the number of nodes in the list */
	if (hare)
	{
		printf("[%p] %d\n", (void *)hare, hare->n);
		count++;
	}

	return (count);
}
