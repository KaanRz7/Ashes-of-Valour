#pragma once
#include "Enemy.h"
#include <string>
#include <vector>

class Character; // Forward declaration of Character class!!!!!!
namespace Game {
	class EliteEnemy : public Enemy {
	public:
		EliteEnemy(const std::string& name);
		void empoweredPoisonBite(std::vector<Character*>& heroes) override; // Function to implement Empowered Poison Bite ability to multiple heroes.
	};
}