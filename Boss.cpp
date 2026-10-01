// Include the header file for the Boss class
#include "Boss.h" 
// Include the other header file alphabetically (No need to incldue Enemy.h, because it is already included in Boss.h)
#include "Ability.h" 
//include libraries alphabetically
#include "Utils.h"
#include <iostream>
#include <string> 
#include <vector>

namespace Game {
	Boss::Boss(const std::string& name)
		: Enemy{ name, 200, 40, 50 } {
		// Initialize abilities for the Boss
		abilities.push_back({ "Ground Slam", Ability::PowerType::Special, 50 });
		abilities.push_back({ "Empowered Shield Block", Ability::PowerType::Defensive, 40 });
		abilities.push_back({ "Mass Heal", Ability::PowerType::Support, 50 });
	}

	void Boss::groundSlam(std::vector<Character*>& heroes){	
		std::cout << getName() << " uses " << RED << "GROUND SLAM!!! " << RESET << "for " << CYAN << "heroes!, " << RESET <<"The ground shakes!" << std::endl;
		for(Character* hero : heroes) {
			hero->takeDamage(50);
		}
		std::erase_if(abilities, [](const Ability& ability) { return ability.name == "Ground Slam"; }); // Remove the used ability from the vector
	}
}