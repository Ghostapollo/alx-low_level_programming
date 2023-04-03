#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	/* Special case: empty list or single node */
	if (!head || !head->next)
		return (NULL);

	/* Initialize the pointers */
	slow = head->next;
	fast = head->next->next;

	/* Find the meeting point */
	while (fast && fast->next)
	{
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}

	/* No loop */
	if (slow != fast)
		return (NULL);

	/* Reset one pointer and move them at the same speed */
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	/* Return the node where they meet again */
	return (slow);
}
