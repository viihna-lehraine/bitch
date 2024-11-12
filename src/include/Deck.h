// File: src/include/Deck.h

#ifndef DECK_H
#define DECK_H

#include <algorithm>
#include <chrono>
#include <random>
#include <stdexcept>
#include <vector>

#include "Card.h"

class Deck {
   public:
	Deck(int numDecks = 1);
	void shuffle();
	Card draw();
	bool isEmpty() const;

   private:
	std::vector<Card> cards;
	std::mt19937 rng;
};

#endif DECK_H