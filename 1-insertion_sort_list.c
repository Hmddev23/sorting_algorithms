#include "sort.h"

/**
  * insertion_sort_list - Sort a doubly linked list.
  *
  * @list: Pointer to the head of the doubly linked list.
  *
  * Return: Nothing.
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *next_node, *curr_node;

	if (!list || !*list || !(*list)->next)
		return;

	curr_node = *list;
	while (curr_node)
	{
		next_node = curr_node->next;
		while (curr_node->prev && curr_node->n < curr_node->prev->n)
		{
			curr_node->prev->next = curr_node->next;
			if (curr_node->next)
				curr_node->next->prev = curr_node->prev;

			curr_node->next = curr_node->prev;
			curr_node->prev = curr_node->prev->prev;
			curr_node->next->prev = curr_node;

			if (curr_node->prev)
				curr_node->prev->next = curr_node;
			else
				*list = curr_node;

			print_list(*list);

		}
		curr_node = next_node;
	}
}
