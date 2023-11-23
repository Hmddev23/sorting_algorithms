#include "deck.h"

/**
  * stng_comp - Compares two strings, card names.
  *
  * @s1: First string to be compared.
  * @s2: Second string to be compared.
  *
  * Return: Signed byte.
  */

int stng_comp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
  * get_numerical_val - Get the card numerical value.
  *
  * @card: Pointer to the card.
  *
  * Return: the card numerical value.
  */

char get_numerical_val(deck_node_t *card)
{
	if (stng_comp(card->card->value, "Ace") == 0)
		return (0);
	if (stng_comp(card->card->value, "1") == 0)
		return (1);
	if (stng_comp(card->card->value, "2") == 0)
		return (2);
	if (stng_comp(card->card->value, "3") == 0)
		return (3);
	if (stng_comp(card->card->value, "4") == 0)
		return (4);
	if (stng_comp(card->card->value, "5") == 0)
		return (5);
	if (stng_comp(card->card->value, "6") == 0)
		return (6);
	if (stng_comp(card->card->value, "7") == 0)
		return (7);
	if (stng_comp(card->card->value, "8") == 0)
		return (8);
	if (stng_comp(card->card->value, "9") == 0)
		return (9);
	if (stng_comp(card->card->value, "10") == 0)
		return (10);
	if (stng_comp(card->card->value, "Jack") == 0)
		return (11);
	if (stng_comp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
  * push_deck_type - Sort a deck of cards.
  *
  * @deck: Pointer to the head of the doubly-linked list.
  *
  * Return: Nothing.
  */

void push_deck_type(deck_node_t **deck)
{
	deck_node_t *iteration, *push, *tmp;

	for (iteration = (*deck)->next; iteration != NULL; iteration = tmp)
	{
		tmp = iteration->next;
		push = iteration->prev;
		while (push != NULL && push->card->kind > iteration->card->kind)
		{
			push->next = iteration->next;
			if (iteration->next != NULL)
				iteration->next->prev = push;
			iteration->prev = push->prev;
			iteration->next = push;
			if (push->prev != NULL)
				push->prev->next = iteration;
			else
				*deck = iteration;
			push->prev = iteration;
			push = iteration->prev;
		}
	}
}

/**
  * push_deck_value - Sort a deck of cards.
  *
  * @deck: Pointer to the head of the doubly-linked list.
  *
  * Return: Nothing.
  */

void push_deck_value(deck_node_t **deck)
{
	deck_node_t *iteration, *push, *tmp;

	for (iteration = (*deck)->next; iteration != NULL; iteration = tmp)
	{
		tmp = iteration->next;
		push = iteration->prev;
		while (push != NULL &&
				push->card->kind == iteration->card->kind &&
				get_numerical_val(push) > get_numerical_val(iteration))
		{
			push->next = iteration->next;
			if (iteration->next != NULL)
				iteration->next->prev = push;
			iteration->prev = push->prev;
			iteration->next = push;
			if (push->prev != NULL)
				push->prev->next = iteration;
			else
				*deck = iteration;
			push->prev = iteration;
			push = iteration->prev;
		}
	}
}

/**
  * sort_deck - Sort a deck of cards with an order.
  *
  * @deck: Pointer to the head of the doubly-linked list.
  *
  * Return: Nothing.
  */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	push_deck_type(deck);
	push_deck_value(deck);
}
