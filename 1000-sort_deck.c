#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * get_card_value - Get the numerical value of a card
 * @str: String representation of the card value
 *
 * Return: Numerical value of the card
 */
int get_card_value(const char *str)
{
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(str, values[i]) == 0)
			return (i);
	}
	return (0);
}

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @deck: Pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
	deck_node_t *prev1 = node1->prev;
	deck_node_t *next1 = node1->next;
	deck_node_t *prev2 = node2->prev;
	deck_node_t *next2 = node2->next;

	if (prev1)
		prev1->next = node2;
	if (next1 && next1 != node2)
		next1->prev = node2;
	if (prev2 && prev2 != node1)
		prev2->next = node1;
	if (next2)
		next2->prev = node1;

	node1->prev = prev2 == node1 ? node2 : prev2;
	node1->next = next2;
	node2->prev = prev1;
	node2->next = next1 == node2 ? node1 : next1;

	if (!node2->prev)
		*deck = node2;
}

/**
 * card_compare - Compare two cards
 * @card1: First card
 * @card2: Second card
 *
 * Return: Difference in card values
 */
int card_compare(const card_t *card1, const card_t *card2)
{
	if (card1->kind != card2->kind)
		return (card1->kind - card2->kind);
	return (get_card_value(card1->value) - get_card_value(card2->value));
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;
	deck_node_t *next;
	int swapped;

	if (!deck || !*deck || !(*deck)->next)
		return;

	do {
		swapped = 0;
		current = *deck;

		while (current->next)
		{
			next = current->next;
			if (card_compare(current->card, next->card) > 0)
			{
				swap_nodes(deck, current, next);
				swapped = 1;
			}
			else
				current = current->next;
		}
	} while (swapped);
}
