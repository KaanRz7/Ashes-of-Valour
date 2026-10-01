#pragma once
#include "Enemy.h"
#include <string>
#include <vector>

class Character; // Forward declaration of Character class!!!!!!
namespace Game {
	class Boss : public Enemy {
	public:
		Boss(const std::string& name);
		// Multiple damage hitter and taker function needed.
		void groundSlam(std::vector<Character*>& heroes) override; // Function to implement Ground Slam ability to multiple enemies. (Boss:: tag cannot be used in .h file)
	};
}