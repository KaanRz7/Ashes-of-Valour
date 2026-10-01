#include "Character.h"
#include "BattleSystem.h"
#include "RoundSystem.h"
#include "GameManager.h"  //no need for pragma once in cpp files. 
#include <string>
#include <vector>
#include <iostream>

using namespace Game; // in main, we can't use namespace, instead, we should use "using namespace Game;" to use classes and functions that included.


	int main() {
		std::vector <Character*> heroes; // Create a vector to hold pointers to hero characters
		std::vector <Character*> enemies; // Create a vector to hold pointers to enemy characters
		BattleSystem battleEngine(heroes, enemies); // Create an instance of BattleSystem with empty vectors for heroes and enemies
		RoundSystem roundEngine(battleEngine); // Create an instance of RoundSystem, passing the BattleSystem instance
		GameManager gameEngine(roundEngine);
		gameEngine.mainMenu(); // Start the main menu	
		return 0;
	}
