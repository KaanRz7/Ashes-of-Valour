#pragma once 
#include "Character.h"
#include <string>
#include <vector>

namespace Game {
	class Enemy : public Character {
	public:
		Enemy(const std::string& name, int health, int attackPower, int shield);
	};
}