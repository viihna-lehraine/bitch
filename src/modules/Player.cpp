// File: src/modules/Player.cpp

#include "../include/Player.h"

Player::Player(const std::string& name) : name(name) {}

std::vector<Card>& Player::getBlindCards() {
	return blindCards;
}

void Player::drawUntilFull(Deck& deck) {
	while (hand.size() < 5) {
		hand.push_back(deck.draw());
	}
}

std::vector<Card>& Player::getHand() {
	return hand;
}

std::vector<Card>& Player::getNakedCards() {
	return nakedCards;
}

const std::string& Player::getName() const {
	return name;
}

bool Player::hasValidPlay(const Card& topCard) const {
	for (const auto& card : hand) {
		if (card.isPlayable(topCard)) {
			return true;
		}
	}
	return false;
}

void Player::layNakedCard(int index) {
	nakedCards.push_back(hand[index]);
	hand.erase(hand.begin() + index);
}

void Player::receiveCard(const Card& card) {
	hand.push_back(card);
}

void Player::showHand() const {
	std::cout << name << "'s Hand: ";

	for (const auto& card : hand) {
		std::cout << card.toString() << " ";
	}

	std::cout << "\n";
}

void Player::showNakedCards() const {
	std::cout << name << "'s Naked Cards: ";

	for (const auto& card : nakedCards) {
		std::cout << card.toString() << " ";
	}

	std::cout << "\n";
}