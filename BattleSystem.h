#pragma once
#include "Character.h"
#include <string>
#include <vector>


namespace Game {
	class BattleSystem {
	public:
		BattleSystem(std::vector<Character*>& heroes, std::vector<Character*>& enemies);
		void createCharacters();
		void showBattleStatus(Character* player, Character* enemy);
		void playerTurn();
		void enemyTurn();
		//getter functions that under this comment for roundsystem and gamemanager to know the heroes and enemies vectors, so they can be used in the round system and game manager.
		std::vector<Character*>& getHeroes(); // Getter function to access the vector of heroes but can't be const they will be assinged once more and change in round system!!!
		std::vector<Character*>& getEnemies();
	private:
		std::vector<Character*> heroes; // Pointer to the vector of characters
		std::vector<Character*> enemies; // Pointer to the vector of enemies
	};
}