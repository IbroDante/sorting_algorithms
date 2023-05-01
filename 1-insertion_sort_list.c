#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t *n1, listint_t *n2)
{
	listint_t *prev, *next;

	prev = n1->prev;
	next = n2->next;

	if (prev != NULL)
		prev->next = n2;
	else
		*h = n2;

	if (next != NULL)
		next->prev = n1;

	n1->next = next;
	n1->prev = n2;
	n2->next = n1;
	n2->prev = prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: A pointer to the head
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curr = (*list)->next; curr != NULL; curr = curr->next)
	{
		while (curr->prev != NULL && curr->n < curr->prev->n)
		{
			prev = curr->prev;
			swap_nodes(list, prev, curr);
			print_list(*list);
		}
	}
}
