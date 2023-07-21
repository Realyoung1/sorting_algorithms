#ifndef DECK_H
#define DECK_H

#include <stdbool.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

/**
 * enum kind_e - Enumeration of card suitsss
 * @SPADE: Spades suitss
 * @HEART: Hearts suitss
 * @CLUB: Clubs suitss
 * @DIAMOND: Diamonds suitss
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing cardss
 *
 * @value: Value of the cardss
 * From "Ace" to "King"
 * @kind: Kind of the cardss
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of cardss
 *
 * @card: Pointer to the card of the nodess
 * @prev: Pointer to the previous node of the listss
 * @next: Pointer to the next node of the listss
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
