// File: src/include/Card.h

#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
   public:
	enum Suit { Hearts,
				Clubs,
				Diamonds,
				Spades,
				Joker };
	enum Rank {
		Ace = 1,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
		JokerRank
	};

	Card(Rank rank, Suit suit);

	std::string toString() const;				 // for displaying the card
	bool isPlayable(const Card& topCard) const;	 // determines if card is playable
	bool isWildCard() const;					 // determines if card is a wildCard (Joker)
	int getValue(bool highAce = false) const;	 // gets the play value of the card

   private:
	Rank rank;
	Suit suit;
};

#endif	// CARD_H