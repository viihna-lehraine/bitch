// File: src/modules/Game.cpp

#include "../include/Game.h"

Game::Game(int numPlayers, int numDecks) : deck(numDecks), currentPlayerIndex(0) {
	for (int i = 0; i < numPlayers; i++) {
		players.emplace_back("Player " + std::to_string(i + 1));
	}
}

void Game::setup() {
	deck.shuffle();
	dealInitialCards();
	determineFirstPlayer();
}

void Game::start() {
	bool gameRunning = true;

	while (gameRunning) {
		Player& currentPlayer = players[currentPlayerIndex];

		std::cout << "\nIt's " << currentPlayer.getName() << "'s turn!\n";
		displayGameState();

		// Top card on the middle stack
		const Card& topCard = middleStack.back();

		// Player attempts to play a card
		if (currentPlayer.hasValidPlay(topCard)) {
			// For now, simulate playing the first valid card
			for (size_t i = 0; i < currentPlayer.getHand().size(); ++i) {
				Card& card = currentPlayer.getHand()[i];
				if (card.isPlayable(topCard)) {
					std::cout << currentPlayer.getName() << " plays " << card.toString() << ".\n";

					// Handle special card behaviors
					handleCardEffect(card);

					// Add the card to the middle stack
					middleStack.push_back(card);
					currentPlayer.getHand().erase(currentPlayer.getHand().begin() + i);
					break;
				}
			}
		} else {
			// Player picks up the middle stack if they cannot play
			std::cout << currentPlayer.getName() << " cannot play and picks up the stack.\n";
			currentPlayer.getHand().insert(currentPlayer.getHand().end(), middleStack.begin(), middleStack.end());
			middleStack.clear();
			middleStack.push_back(deck.draw());	 // Restart stack with a new card
		}

		// Check for endgame conditions
		if (deck.isEmpty() && currentPlayer.getHand().empty() && currentPlayer.getNakedCards().empty()) {
			std::cout << currentPlayer.getName() << " wins the game!\n";
			gameRunning = false;
		}

		// Move to the next player
		currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
	}

	std::cout << "Game Over!\n";
}

void Game::handleCardEffect(const Card& card) {
	switch (card.getValue()) {
		case 7:
			std::cout << "7 played! The next player must draw 2 cards or play a valid counter.\n";

			// *DEV-NOTE* implement stacking effect logic here

			break;
		case 8:
			std::cout << "8 played! Skipping the next player.\n";

			currentPlayerIndex = (currentPlayerIndex + 1) % players.size();

			break;
		case 9:
			std::cout << "9 played! Next player must play <= 9.\n";

			break;
		case 10:
			std::cout << "10 played! Clearing the middle stack.\n";

			middleStack.clear();

			break;
		case Card::JokerRank:
			std::cout << "Joker played! Acts as any card.\n";

			break;
		default:
			break;
	}
}

void Game::dealInitialCards() {
	for (auto& player : players) {
		for (int i = 0; i < 4; ++i) {
			player.getBlindCards().push_back(deck.draw());
		}

		for (int i = 0; i < 9; ++i) {
			player.receiveCard(deck.draw());
		}
	}

	middleStack.push_back(deck.draw());
}

void Game::determineFirstPlayer() {
	std::srand(std::time(nullptr));
	currentPlayerIndex = std::rand() % players.size();
	std::cout << players[currentPlayerIndex].getName() << " goes first!\n";
}

void Game::displayGameState() const {
	std::cout << "Middle Stack: ";
	for (const auto& card : middleStack) {
		std::cout << card.toString() << " ";
	}
	std::cout << "\n";

	for (const auto& player : players) {
		player.showHand();
		player.showNakedCards();
	}
}
