#pragma once
#include "Enemy.h"
namespace Game {
	Enemy::Enemy(const std::string& name, int health, int attackPower, int shield)
		: Character(name, health, attackPower, shield) {
	}
} 