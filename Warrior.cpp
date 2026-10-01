#include "Warrior.h"
#include "Ability.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <vector>
namespace Game {
	Warrior::Warrior(const std::string& name)
		: Character{ name, 100, 30, 10 } {
		// Initialize abilities for the Warrior
		abilities.push_back({ "Rage", Ability::PowerType::Special, 35 });
		abilities.push_back({ "Shield Block", Ability::PowerType::Defensive, 20 });
		abilities.push_back({ "Battle Cry", Ability::PowerType::Support, 15 });
	}
	void Warrior::rage(Character* enemy) {
		std::cout << getName() <<" uses " << RED <<"RAGE!!!" << RESET << std::endl;
		enemy->takeDamage(35); // Deal 35 damage to the enemy
		heal(20);// Restore 15 health to the warrior
		std::erase_if(abilities, [](const Ability& ability) { return ability.name == "Rage"; }); // Remove the used ability from the vector
	}

}