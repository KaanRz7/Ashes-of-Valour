#include "Mage.h"
#include "Ability.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <vector>
namespace Game {
	Mage::Mage(const std::string& name)
		: Character{ name, 80, 20, 20 } {
		// Initialize abilities for the Mage
		abilities.push_back({ "Meteor", Ability::PowerType::Special, 15 });
		abilities.push_back({ "Ice Shield", Ability::PowerType::Defensive, 20 });
		abilities.push_back({ "Heal Allies", Ability::PowerType::Special, 20 });
	}
	void Mage::meteor(std::vector<Character*>& enemies){
		std::cout << getName() << " uses " << YELLOW <<"METEOR!!! " << RESET << RED <<"enemies!, "<< RESET << YELLOW <<"METEOR rain starts!" << RESET << std::endl;
		for (Character* enemy : enemies) {
			enemy->takeDamage(15+getAttackPower()); // Deal 20 damage to each enemy (Note: no need to check whether the enemy is alive or not, as round system will handle it)
		}
		std::erase_if(abilities, [](const Ability& ability) { return ability.name == "Meteor"; });
	}
	void Mage::healAllies(std::vector<Character*>& heroes) {
		std::cout << getName() << " uses " << GREEN << "HEAL!!! " << RESET << "for its "<< CYAN << "allies!" << RESET << std::endl;
		for (Character* hero : heroes) {
			hero->heal(15); // Restore 15 health to each ally
		}
		std::erase_if(abilities, [](const Ability& ability) { return ability.name == "Heal Allies"; });
	}
}