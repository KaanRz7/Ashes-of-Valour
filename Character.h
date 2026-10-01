#pragma once
#include "Ability.h"
#include <string>
#include <vector>

namespace Game {
	class Character {
	public:
		Character(const std::string& name, int health, int attackPower, int shield);
		std::string showCharacterInfo() const;
		const std::string& getName() const;
		const int getAttackPower() const;
		const int getHealth() const;
		std::vector <Ability>& getAbilities();
		void heal(int amount); // Function to heal the character by a certain amount
		void showAbilities() const; //Function to show all abilities of character
		void displayActiveAbilities() const; //Function to display existed abilities of character!
		void takeDamage(int damage);
		void attack(Character* target);
		void useAbility(Ability& ability, Character* target); // Function to use an ability on a target character
		bool isSpecialAbility(const Ability& ability) const; // Function to check if the character is alive (health > 0)

		//virtuals for special abilities, to be overridden in derived classes
		// WARRIOR
		virtual void rage(Character* target) {}
		// MAGE
		virtual void meteor(std::vector<Character*>& enemies) {}
		virtual void healAllies(std::vector<Character*>& heroes) {}
		// ELITE ENEMY
		virtual void empoweredPoisonBite(std::vector<Character*>& heroes) {}
		//BOSS
		virtual void groundSlam(std::vector<Character*>& heroes) {}
	private:
		std::string name;
		int health;
		int attackPower;
		int shield;
		int maxHealth;
		int maxShield;
	protected:  //protected if a friend class or a class which is inheritance of Character.h are able to access it but only including is not enough!
		std::vector <Ability> abilities; // Vector to hold the character's abilities
	};
}