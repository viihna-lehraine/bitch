// File: src/modules/Deck.cpp

#include "../include/Deck.h"

bool Deck::isEmpty() const {
	return cards.empty();
}

Card Deck::draw() {
	if (cards.empty()) {
		throw std::out_of_range("Deck is empty");
	}

	Card card = cards.back();
	cards.pop_back();

	return card;
}

Deck::Deck(int numDecks) {
	for (int i = 0; i < numDecks; i++) {
		for (int suit = Card::Clubs; suit <= Card::Spades; suit++) {
			for (int rank = Card::Ace; rank <= Card::King; rank++) {
				cards.emplace_back(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
			}
		}

		cards.emplace_back(Card::JokerRank, Card::Joker);
	}

	rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

void Deck::shuffle() {
	std::shuffle(cards.begin(), cards.end(), rng);
}