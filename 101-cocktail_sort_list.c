#include "sort.h"

/**
  * swap_front_node - Swap a node in a doubly-linked list.
  *
  * @list: Pointer to the head.
  * @tail: Pointer to the tail.
  * @shaker: Pointer to current node.
  *
  * Return: Nothing.
  */

void swap_front_node(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp_val = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp_val;
	else
		*list = tmp_val;
	tmp_val->prev = (*shaker)->prev;
	(*shaker)->next = tmp_val->next;
	if (tmp_val->next != NULL)
		tmp_val->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp_val;
	tmp_val->next = *shaker;
	*shaker = tmp_val;
}

/**
  * swap_back_node - Swap a node with the node behind it.
  *
  * @list: Pointer to the head.
  * @tail: Pointer to the tail.
  * @shaker: Pointer to the current node.
  *
  * Return: Nothing.
  */

void swap_back_node(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp_val = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp_val;
	else
		*tail = tmp_val;
	tmp_val->next = (*shaker)->next;
	(*shaker)->prev = tmp_val->prev;
	if (tmp_val->prev != NULL)
		tmp_val->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp_val;
	tmp_val->prev = *shaker;
	*shaker = tmp_val;
}

/**
  * cocktail_sort_list - sort a dll with cocktail shaker algorithm.
  *
  * @list: Pointer to the head of a doubly-linked list.
  *
  * Return: Nothing.
  */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool state = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (state == false)
	{
		state = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_front_node(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				state = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_back_node(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				state = false;
			}
		}
	}
}
