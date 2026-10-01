#pragma once
#include "Character.h"
#include <string>
#include <vector>

namespace Game {
	class Mage : public Character {
	public:
		Mage(const std::string& name);
		void meteor(std::vector<Character*>& enemies) override; // Function to implement Meteor ability to multiple enemies.
		void healAllies(std::vector<Character*>& heroes) override; // Function to implement Heal ability to multiple allies.
	};
}