#pragma once 
#include "BattleSystem.h"
#include <string>
#include <vector>

namespace Game {
	class RoundSystem {
	public:
		RoundSystem(BattleSystem& battleEngine);
		void startRound();
		void endRound(std::vector<Character*>& heroes, std::vector<Character*>& enemies);
		bool checkBattleStatus(const std::vector<Character*>& heroes, const std::vector<Character*>& enemies);
		// second getter functions for gamemanager to know the heroes and enemies vectors, so they can be used in the  game manager by using roundsystem instance.
	private:
		BattleSystem& battleEngine; // Instance of BattleSystem to manage turns!!!!!
	};
}