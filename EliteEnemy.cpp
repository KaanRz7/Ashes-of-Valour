#include "EliteEnemy.h"
#include "Ability.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <vector>
namespace Game {
	EliteEnemy::EliteEnemy(const std::string& name)
		: Enemy{ name, 100, 30, 10 } {
		// Initialize abilities for the EliteEnemy
		abilities.push_back({ "Claw Swipe", Ability::PowerType::Offensive, 20 });
		abilities.push_back({ "Empowered Poison Bite", Ability::PowerType::Special, 25 });
		abilities.push_back({ "Necrotic Regeneration", Ability::PowerType::Support, 20 });
	}

	void EliteEnemy::empoweredPoisonBite(std::vector<Character*>& heroes) {
		std::cout << getName() << " uses "<< RED << "EMPOWERED POISON BITE!!!" << RESET << "for " << CYAN << "heroes!, " << GREEN << "POISON cloud forms!" << RESET << std::endl;
		for (Character* hero : heroes) {
			hero->takeDamage(25); // Deal 20 damage to each hero (Note: no need to check whether the hero is alive or not, as round system will handle it)
		}
		std::erase_if(abilities, [](const Ability& ability) { return ability.name == "Empowered Poison Bite"; });  // Remove the used ability from the vector
	}
}