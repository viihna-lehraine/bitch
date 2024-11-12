// File: src/include/Game.h

#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Deck.h"
#include "Player.h"

class Game {
   public:
	Game(int numPlayers, int numDecks = 1);

	void setup();							  // setup the game
	void start();							  // start the main game loop
	void handleCardEffect(const Card& card);  // handle special card effects

   private:
	Deck deck;						// the main deck of cards
	std::vector<Card> middleStack;	// stack of played cards in the center
	std::vector<Player> players;	// list of players in the game
	int currentPlayerIndex;			// index of the current player's turn

	void dealInitialCards();		// deal initial cards to players
	void determineFirstPlayer();	// determine who starts first
	void displayGameState() const;	// display the current game state
};

#endif GAME_H
