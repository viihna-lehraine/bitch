// File: src/Main.cpp

#include "include/Main.h"

int main() {
	Startup::displayStartupInfo();

	Game game(4, 1);  // 4 players, 1 deck
	game.setup();
	game.start();

	return 0;
}