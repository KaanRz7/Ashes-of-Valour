#include "Character.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <vector>

namespace Game {
	Character::Character(const std::string& name, int health, int attackPower, int shield)
		: name(name), health(health), attackPower(attackPower), shield(shield), maxHealth(health), maxShield(shield) {
	}
	std::string Character::showCharacterInfo() const {
		return "Name: " + name + "\nHealth: " + std::to_string(health) + "\nAttack Power: " + std::to_string(attackPower) + "\nShield: " + std::to_string(shield);
	}
	const std::string& Character::getName() const {
		return name;
	}
	const int Character::getAttackPower() const {
		return attackPower;
	}
	std::vector <Ability>& Character::getAbilities() {
		return abilities;
	}
	const int Character::getHealth() const {
		return health;
	}
	void Character::heal(int amount) {
		health += amount;   // Increase health by the specified amount
		if (health >= maxHealth) {
			health = maxHealth;
			std::cout << GREEN << "The Character's health is full!" << RESET << std::endl;
		}
		else {
			std::cout << name << CYAN << " healed for " << amount << " health. -> Current health: " << RESET << GREEN << health << RESET << std::endl;
		}
	}

	void Character::showAbilities() const {
		std::cout << RED << "NOTE: " << RESET;
		std::cout << GREEN << "Offensive effects attackDamage, ";
		std::cout << " Defensive effects shield, ";
		std::cout << " Support effects heal." << RESET << std::endl;
		int i = 0;
		std::cout << CYAN << "------------------------------------------------------\n" << RESET;
		std::cout << '\n';
		std::cout << YELLOW << "            * HERE ARE THE ABILITIES *                        \n" << RESET;
		for (const auto& ability : abilities) { // Loop through each ability and display its details
			std::cout << YELLOW << "----------------------------------------------------------\n" << RESET;
			std::cout <<RED <<  "[" << 1 + i <<"]"<< RESET << YELLOW << " Ability Name: " << RESET << ability.name << std::endl;
			std::cout << YELLOW <<"Power Type: " << RESET;
			switch (ability.type) {
			case Ability::PowerType::Offensive:
			{
				std::cout << "Offensive" << std::endl;
				break;
			}
			case Ability::PowerType::Defensive:
			{
				std::cout << "Defensive" << std::endl;
				break;
			}
			case Ability::PowerType::Support:
			{
				std::cout << "Support" << std::endl;
				break;
			}
			case Ability::PowerType::Special:
			{
				std::cout << "Special" << std::endl;
				break;
			}
			}
			std::cout << YELLOW <<"Amount: " << RESET << ability.amount << std::endl;
			i++;
		}
	}
	void Character::displayActiveAbilities() const {
		int i = 0;

		for (const auto& ability : abilities) { // Loop through each ability and display its details
			std::cout << RED << "[" << 1 + i << "]" << RESET << YELLOW << " Ability Name: " << RESET << ability.name << std::endl;
			std::cout << YELLOW << "Power Type: " << RESET;
			switch (ability.type) {
			case Ability::PowerType::Offensive:
			{
				std::cout << RED << "Offensive\n" << RESET;
				break;
			}
			case Ability::PowerType::Defensive:
			{
				std::cout << CYAN <<  "Defensive\n" << RESET;
				break;
			}
			case Ability::PowerType::Support:
			{
				std::cout << GREEN << "Support\n" << RESET;
				break;
			}
			case Ability::PowerType::Special:
				std::cout << CYAN << "Special\n" << RESET;
				break;
			}

			std::cout << YELLOW << "Amount: " << RESET << ability.amount << std::endl;
			i++;
			std::cout << CYAN << "------------------------------------------------------\n" << RESET;
		}
	}

	void Character::takeDamage(int damage) {
		int effectiveDamage = damage - shield; // Calculate effective damage after shield
		if (effectiveDamage < 0) {
			effectiveDamage = 0; // Prevent negative damage
		}
		shield -= damage;
		if (shield < 0) {
			shield = 0;
		}
		health -= effectiveDamage; // Reduce health by effective damage
		if (health < 0) {
			health = 0; // Prevent health from going below zero
		}
		std::cout << name << " took " << RED << damage << " damage." << RESET << WHITE <<" Remaining health : " << RESET << GREEN << health << RESET << " , Remaining shield : " << CYAN << shield <<  RESET << std::endl;
	}
	void  Character::attack(Character * target) {
		std::cout << name << RED << " attacks " << RESET << target->name << " for " << RED << attackPower << " damage!" << RESET <<  std::endl;
		target->takeDamage(attackPower); // Call takeDamage on the target character
	}
	void Character::useAbility(Ability & ability, Character* target) {
		switch (ability.type) {
		case Ability::PowerType::Offensive:
		{
			std::cout << name << " uses " << CYAN << ability.name << RESET << "! on " << YELLOW << target->name << RESET << " for " << RED << ability.amount + attackPower << " damage!" << RESET << std::endl;
			target->takeDamage(ability.amount + attackPower); // Call takeDamage on the target character
			break;
		}
		case Ability::PowerType::Defensive:
		{
			shield += ability.amount; // Increase shield
			if (shield > maxShield) {
				shield = maxShield;
			}
			std::cout << name << " uses " << CYAN << ability.name << RESET << " to increase shield by " << CYAN << ability.amount << RESET << "." << std::endl;
			break;
		}
		case Ability::PowerType::Support:
		{
			health += ability.amount; // Heal the target character
			std::cout << name << " uses " << CYAN << ability.name << RESET << " to heal" << " for " << GREEN << ability.amount << RESET << "." << std::endl;
			if (health > maxHealth) {
				health = maxHealth;
				std::cout << GREEN << "The Character's health is full!" << RESET << std::endl;
			}
			break;
		}
		}
		std::erase_if(abilities, [&ability](const auto& x) { return &x == &ability; }); // Remove the used ability from the vector
	}
	bool Character::isSpecialAbility(const Ability & ability) const {
		if (Ability::PowerType::Special == ability.type) {
			return true; // check whether ability is a special ability or not.
		}
		return false;
	}
}