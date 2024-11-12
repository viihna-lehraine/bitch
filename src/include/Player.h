// File: src/include/Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

#include "Card.h"
#include "Deck.h"

class Player {
   public:
	Player(const std::string& name);

	void drawUntilFull(Deck& deck);				   // draw cards until hand has 5 cards
	bool hasValidPlay(const Card& topCard) const;  // check if player has a valid play
	void layNakedCard(int index);				   // lay a card face up on top of a blind card
	void receiveCard(const Card& card);			   // add a card to the player's hand
	void showHand() const;						   // display a player's hand
	void showNakedCards() const;				   // display a player's naked cards

	const std::string& getName() const;
	std::vector<Card>& getHand();
	std::vector<Card>& getNakedCards();
	std::vector<Card>& getBlindCards();

   private:
	std::string name;
	std::vector<Card> hand;
	std::vector<Card> nakedCards;
	std::vector<Card> blindCards;
};

#endif PLAYER_H