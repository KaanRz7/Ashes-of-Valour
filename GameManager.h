#pragma once
#include "RoundSystem.h"
#include <iostream>
#include <string>
#include <vector>

namespace Game {
	class GameManager {
	public:
		GameManager(RoundSystem& m_roundEngine);
		void printWelcomeMessage() const; // Function to display the welcome message
		void startGame();
		void mainMenu(); // Function to display the main menu and handle user input
	private:
		RoundSystem& m_roundEngine; // Instance of RoundSystem to manage rounds
	};
}