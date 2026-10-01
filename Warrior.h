#pragma once 
#include "Character.h"
#include <string>
#include <vector>

namespace Game {
	class Warrior : public Character {
	public:
		Warrior(const std::string& name);
		void rage(Character* enemy) override;
	};
}