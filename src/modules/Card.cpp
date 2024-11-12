// File: src/modules/Card.cpp

#include "../include/Card.h"

Card::Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}

std::string Card::toString() const {
	static const char* rankNames[] = {"", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Joker"};
	static const char* suitNames[] = {"Clubs", "Diamonds", "Hearts", "Spades", "Joker"};

	if (suit == Joker) {
		return "Joker";
	}
	return std::string(rankNames[rank]) + " of " + suitNames[suit];
}

bool Card::isPlayable(const Card& topCard) const {
	if (suit == Joker) return true;	 // Jokers can always be played
	if (rank == Two) return true;	 // Twos can always be played

	// Aces (high or low) and other special rules (7, 8, 9, etc.) depend on context
	if (rank == Ace || rank == Seven || rank == Eight || rank == Nine || rank == Ten) {
		return true;  // Placeholder for now
	}

	// general rule: card must be >= the top card's value
	return getValue() >= topCard.getValue();
}

bool Card::isWildCard() const {
	return suit == Joker;
}

int Card::getValue(bool highAce) const {
	if (rank == Ace) {
		return highAce ? 14 : 1;  // Ace can be high or low
	}
	if (rank == JokerRank) {
		return 0;  // Jokers wild, no intrinsic value
	}
	return rank;
}
