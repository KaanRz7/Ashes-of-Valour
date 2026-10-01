#include "BattleSystem.h"
#include "Character.h"
#include "Ability.h"
#include "Warrior.h"
#include "Archer.h"
#include "Mage.h"
#include "Enemy.h"
#include "EliteEnemy.h"
#include "NormalEnemy.h"
#include "Boss.h"
#include "Utils.h"
#include <cctype>  //for std::isdigit etc.
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>



namespace Game {
	BattleSystem::BattleSystem(std::vector<Character*>& heroes, std::vector<Character*>& enemies) : heroes(heroes), enemies(enemies) { //in singular initiliaze, we must use () instead of {}, {} for initializer list.
	
	}
	std::vector<Character*>& BattleSystem::getHeroes() { 
		return heroes; 
	}
	std::vector<Character*>& BattleSystem::getEnemies() { 
		return enemies; 
	}
	void BattleSystem::createCharacters() { // Function to create characters (heroes and enemies), use it in the main.cpp after creating the general menu.
		char again = 'Y';
		do {
			clearConsole();
			std::cout << CYAN << "==========================================================\n"
				<< YELLOW << "                *  ASHES OF VALOUR RPG  *      \n"
				<< CYAN << "==========================================================\n" << RESET << std::endl;

			std::cout << "      " << GREEN << "* Would you like to create hero or enemy? *" << RESET << std::endl;

			std::cout << CYAN << "===========================================================" << RESET << std::endl;
			std::cout << YELLOW << "[1]" << RESET << " Hero" << std::endl;
			std::cout << YELLOW << "[2]" << RESET << " Enemy" << std::endl;
			std::cout << CYAN << "===========================================================" << RESET << std::endl;

			std::cout << RED << "NOTE:" << RESET << " You must create at least one HERO and ENEMY, \n";
			std::cout << "if you have not created one of them, you are forced to create character first.\n" << std::endl;
			int choice;  //input validation!
			while (true) {
				std::cout << GREEN << "Your choice is: " << RESET;
				std::cin >> choice;
				if (std::cin.fail() || (choice != 1 && choice != 2)) {
					std::cin.clear(); // clear the error flag
					std::cin.ignore(10000, '\n'); // discard invalid input
					std::cout << RED << "Invalid input. Please enter 1 for Hero or 2 for Enemy: " << RESET;
					continue; // prompt for input again
				}
				std::cin.ignore(10000, '\n'); // discard any remaining input (such as newline characters, extra characters after the number (like 1xyz), etc.)
				break; // valid input, exit the loop
			}
			bool isValid = true;
			bool hasLetter = false;
			switch (choice) {
			case 1: {
				clearConsole();
				std::cout << "     "<< CYAN << "* Heroes are : Warrior, Archer, Mage * \n" << RESET << std::endl;
				std::cout << "Please select a " << CYAN << "hero " << RESET << "to create : " << std::endl;
				std::cout << "===========================================================" << std::endl;
				std::cout << YELLOW << "[1] " << RESET << "Warrior = > Health : " << CYAN << "100" << RESET << ", AttackPower : " << CYAN << "30" << RESET << ", Shield : " << CYAN << "10" << RESET << std::endl;
				std::cout << "Abilities are: " << CYAN << "Rage" << RESET << ", Shield Block, BattleCry" << std::endl;
				std::cout << "===========================================================" << std::endl;
				std::cout << YELLOW << "[2] " << RESET << "Archer = > Health : " << CYAN << "80" << RESET << ", AttackPower : " << CYAN << "25" << RESET << ", Shield : " << CYAN << "15" << RESET << std::endl;
				std::cout << "Abilities are: Precise Shot, Evasion, Heal Arrow" << std::endl;
				std::cout << "===========================================================" << std::endl;
				std::cout << YELLOW << "[3] "<< RESET << "Mage = > Health : " << CYAN << "80" << RESET << ", AttackPower : " << CYAN << "20" << RESET << ", Shield : " << CYAN << "20" << RESET << std::endl;
				std::cout << "Abilities are: " << CYAN << "Meteor" << RESET << ", Ice Shield, " << CYAN << "Heal Allies" << RESET << std::endl;
				std::cout << "===========================================================" << std::endl;
				std::cout << CYAN << "Note: Abilities shown in cyan are Special Abilities." << RESET << std::endl;
				std::cout << '\n';
				int choice1; // input validation!
				while (true) {
					std::cout << GREEN << "Your choice is: " << RESET;
					std::cin >> choice1;
					if (std::cin.fail() || (choice1 != 1 && choice1 != 2 && choice1 != 3)) {
						std::cin.clear(); // clear the error flag
						std::cin.ignore(10000, '\n'); // discard invalid input
						std::cout << RED << "Invalid input. Please enter '1' for Warrior, '2' for Archer, or '3' for Mage: " << RESET;
						std::cout << '\n';
						continue; // prompt for input again
					}
					std::cin.ignore(10000, '\n'); // discard any remaining input (such as newline characters, extra characters after the number (like 1xyz), etc.)
					break; // valid input, exit the loop
				}
				std::cout << '\n';
				std::cout << "Enter a " << CYAN << "name " << RESET << "for the hero: ";
				std::string hero_name;
				while (true) { // input validation!
					std::getline(std::cin, hero_name); // by using getline(), we can allow spaces in the hero name, but we will validate that it does not start or end with a space and does not contain digits or symbols!!!
					if (hero_name.empty()) {
						std::cout << RED << "Invalid input. Please enter a non-empty name for the hero: " <<  RESET;
						std::cout << '\n';
						continue;
					}
					if (std::isspace(hero_name.front()) || std::isspace(hero_name.back())) {
						std::cout << RED << "Invalid input. Please enter a name that does not start or end with a space: " << RESET; //hero name can not start or end with a space.
						std::cout << '\n';
						continue;
					}
					isValid = true;
					hasLetter = false;
					for (char c : hero_name) {
						if (std::isalpha(c)) {
							hasLetter = true; //hero name must contain at least one letter.
						}
						else if (!std::isspace(c)) {
							isValid = false;  //hero name can not contain whitespaces.
							break;
						}
					}
					if (!isValid || !hasLetter) {
						std::cout << RED << "Invalid input. Hero name must contain letters and cannot include digits/symbols: " << RESET;
						std::cout << '\n';
						continue;
					}
					break; // Valid input!
				}
				switch (choice1) {
				case 1:
				{
					Warrior* warrior = new Warrior(hero_name);
					heroes.push_back(warrior);
					break;
				}
				case 2:
				{
					Archer* archer = new Archer(hero_name);
					heroes.push_back(archer);
					break;
				}
				case 3:
				{
					Mage* mage = new Mage(hero_name);
					heroes.push_back(mage);
					break;
				}
				break;
				}
			}
			break;
			case 2:
			{
				clearConsole();
				std::cout << "      "<< RED <<" * Enemies are : Normal Enemy, Elite Enemy, Boss * \n" << RESET << std::endl;
				std::cout << "Please select an enemy to encounter:" << std::endl;
				std::cout << "===========================================================" << std::endl;
				std::cout << YELLOW << "[1] " << RESET <<"Normal Enemy = > Health : " << CYAN << "80" << RESET << ", AttackPower : " << CYAN << "15" << RESET << ", Shield : " << CYAN << "5" << RESET << std::endl;
				std::cout << "Abilities are: Poison Bite" << std::endl;
				std::cout << "===========================================================" << std::endl;
				std::cout << YELLOW << "[2] " << RESET <<"Elite Enemy = > Health : " << CYAN << "100" << RESET << ", AttackPower : " << CYAN << "30" << RESET << ", Shield : " << CYAN << "10" << RESET << std::endl;
				std::cout << "Abilities are: " << CYAN << "Empowered Poison Bite" << RESET << std::endl;
				std::cout << "===========================================================" << std::endl;
				std::cout << YELLOW << "[3] " << RESET << "Boss = > Health : " << CYAN << "200" << RESET << ", AttackPower : " << CYAN << "40" << RESET << ", Shield : " << CYAN << "50" << RESET << std::endl;
				std::cout << "Abilities are: " << CYAN << "Ground Slam" << RESET << ", Empowered Shield Block, Mass Heal" << std::endl;
				std::cout << "===========================================================" << std::endl;
				std::cout << CYAN << "Note: Abilities shown in cyan are Special Abilities." << RESET << std::endl;
				std::cout << '\n';
				int choice2;
				while (true) { //input validation!
					std::cout << GREEN << "Your choice is: " << RESET;
					std::cin >> choice2;
					if (std::cin.fail() || (choice2 != 1 && choice2 != 2 && choice2 != 3)) {
						std::cin.clear(); // clear the error flag
						std::cin.ignore(10000, '\n'); // discard invalid input
						std::cout << RED << "Invalid input. Please enter '1' for NormalEnemy, '2' for EliteEnemy, or '3' for Boss: " << RESET;
						std::cout << '\n';
						continue; // prompt for input again
					}
					std::cin.ignore(10000, '\n'); // discard any remaining input (such as newline characters, extra characters after the number (like 1xyz), etc.)
					break; // valid input, exit the loop
				}
				std::cout << "Enter a " << CYAN << "name " << RESET <<"for the enemy : ";
				std::string enemy_name;
				while (true) { // input validation!
					std::getline(std::cin, enemy_name); // by using getline(), we can allow spaces in the enemy name, but we will validate that it does not start or end with a space and does not contain digits or symbols!!!
					if (enemy_name.empty()) {
						std::cout << RED << "Invalid input. Please enter a non-empty name for the enemy: " << RESET;
						continue;
					}
					if (std::isspace(enemy_name.front()) || std::isspace(enemy_name.back())) {
						std::cout << RED << "Invalid input. Please enter a name that does not start or end with a space: " << RESET; //enemy name cannot start or end with a space.
						continue;
					}
					isValid = true;
					hasLetter = false;
					for (char c : enemy_name) {
						if (std::isalpha(c)) {
							hasLetter = true; //enemy name must contain at least one letter.
						}
						else if (!std::isspace(c)) {
							isValid = false;  //enemy name cannot contain digits or symbols.
							break;
						}
					}
					if (!isValid || !hasLetter) {
						std::cout << RED << "Invalid input. Enemy name must contain letters and cannot include digits/symbols: " << RESET;
						continue;
					}
					break; // Valid input!
				}
				switch (choice2) {
				case 1:
				{
					NormalEnemy* normalEnemy = new NormalEnemy(enemy_name); //raw pointer is used ( for learning purposes =)), in the future unique and shared ptrs will be integrated into new systems.
					enemies.push_back(normalEnemy);
					break;
				}
				case 2:
				{
					EliteEnemy* eliteEnemy = new EliteEnemy(enemy_name);
					enemies.push_back(eliteEnemy);
					break;
				}
				case 3:
				{
					Boss* boss = new Boss(enemy_name);
					enemies.push_back(boss);
					break;
				}
				break;
				}
			}
			break;
			}
			std::cout << '\n' << std::endl;
			std::cout << GREEN << "Character created successfully!" << RESET << std::endl;
			std::cout << "Would you like to create another " << CYAN << "character ? " << RESET << "(" << GREEN << "Y" << RESET <<  "/" << RED << "N" << RESET << ") : ";
			while (true) {
				std::cin >> again;
				if (again == 'Y' || again == 'y' || again == 'N' || again == 'n') {
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					break;
				}
				else {
					std::cout << RED << "Invalid input. Please enter " << GREEN <<  "'Y'" << RESET << " for Yes or " << RED << "'N'" << RESET << " for No: " << RESET;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					continue;
				}
			}

			if (again == 'N' || again == 'n') {
				if (heroes.empty() || enemies.empty()) {
					std::cout << RED << "\n[!] You must create at least one Hero and one Enemy before exiting!\n"<< RESET;
					std::cout << GREEN << "Press Enter to continue..." << RESET;
					std::cin.get(); // std::cin.get() used for get one random key as input (used for press enter to continue etc...)	
					again = 'Y';
				}
			}
		} while (again == 'Y' || again == 'y');
	}
	void BattleSystem::showBattleStatus(Character* player, Character* enemy) {
		std::cout << CYAN << "================================================= * ROUND STATUS REPORT * =================================================" << RESET << std::endl;
		std::cout << std::endl;

		std::cout << GREEN << "+-------------------------------------------------------+" << RESET << std::endl;
		std::cout << GREEN << "|                   PLAYER STATS                        |" << RESET << std::endl;
		std::cout << GREEN << "+-------------------------------------------------------+" << RESET << std::endl;
		std::cout << GREEN << "| " << std::left << std::setw(53) << player->showCharacterInfo() << "|" << RESET << std::endl;
		std::cout << GREEN << "+-------------------------------------------------------+" << RESET << std::endl;

		std::cout << "\n" << YELLOW << "---------------- PLAYER ABILITIES ------------------------" << RESET << std::endl;
		player->displayActiveAbilities();
		std::cout << YELLOW << "----------------------------------------------------------" << RESET << std::endl;
		std::cout << "\n" << RED << "+-------------------------------------------------------+" << RESET << std::endl;
		std::cout << RED << "|                    ENEMY STATS                        |" << RESET << std::endl;
		std::cout << RED << "+-------------------------------------------------------+" << RESET << std::endl;
		std::cout << RED << "| " << std::left << std::setw(53) << enemy->showCharacterInfo() << "|" << RESET << std::endl;
		std::cout << RED << "+-------------------------------------------------------+" << RESET << std::endl;

		std::cout << "\n" << YELLOW << "----------------- ENEMY ABILITIES ------------------------" << RESET << std::endl;
		enemy->displayActiveAbilities();
		std::cout << YELLOW << "----------------------------------------------------------" << RESET << std::endl;
		std::cout << std::endl;
		std::cout << RED << " >> NOTE: " << RESET << "Status report shows only the stats of the " << std::endl;
		std::cout << CYAN << "    characters " << RESET << "that are selected!" << std::endl;
		std::cout << std::endl;
		std::cout << RED << "+--------------------------------------------------------+\n" << RESET << std::endl;
		std::cout << std::endl;
	}

	void BattleSystem::playerTurn() {
		std::cout << YELLOW << "\n===================== * PLAYER TURN * =====================\n" << RESET;
		std::cout << CYAN << "Player's turn!, please choose a hero !\n" << RESET << std::endl;
		std::cout << YELLOW <<"Available heroes are:" << RESET << std::endl;
		std::cout << CYAN << "-------------------------------------------\n" << RESET;
		for (size_t i = 0; i < heroes.size(); ++i) {
			std::cout << RED <<"[" << i + 1 << "]" << RESET << heroes[i]->showCharacterInfo() << std::endl;
			std::cout << CYAN << "-------------------------------------------\n" << RESET;
		}
		std::cout << "Please select a " << CYAN << "hero " << RESET << "by entering the corresponding number, \n";
		int hero_choice;
		while (true) { // input validation!
			std::cout << GREEN << "Your choice is: "<< RESET;
			std::cin >> hero_choice;
			if (std::cin.fail() || hero_choice < 1 || hero_choice > static_cast<int>(heroes.size())) { // static_cast<int>(heroes.size()) is used to avoid comparison between signed and unsigned integers. (size_t is unsigned, int is signed)!!!
				std::cin.clear(); // clear the error flag
				std::cin.ignore(10000, '\n'); // discard invalid input
				std::cout << RED << "Invalid input. Please enter a valid hero number: " << RESET;
				continue; // prompt for input again
			}
			std::cin.clear();
			std::cin.ignore(10000, '\n'); // discard any remaining input (such as newline characters, extra characters after the number (like 1xyz), etc.)
			break; // valid input, exit the loop
		}
		std::cout << CYAN << "-------------------------------------------------------" << RESET << std::endl;
		std::cout << YELLOW << "          * You selected: " << heroes[hero_choice - 1]->getName() <<" as hero *" << RESET << std::endl;
		std::cout << CYAN << "-------------------------------------------------------\n" << RESET << std::endl;
		std::cout << RED << "Please select an enemy to attack!" << RESET << std::endl;
		std::cout << YELLOW << "Available enemies are:" << RESET << std::endl;
		std::cout << CYAN << "-------------------------------------------\n" << RESET;
		for (size_t i = 0; i < enemies.size(); ++i) {
			std::cout << RED <<"["<< i + 1 << "]" << RESET << enemies[i]->showCharacterInfo() << std::endl;
			std::cout << CYAN << "-------------------------------------------\n" << RESET;
		} 
		std::cout << "Now, please select an " << RED <<"enemy "<< RESET << "by entering the corresponding number, \n";
		std::cout << GREEN << "Your choice is: " << RESET;
		int enemy_choice;
		while (true) { // input validation!
			std::cin >> enemy_choice;
			if (std::cin.fail() || enemy_choice < 1 || enemy_choice > static_cast<int>(enemies.size())) { // static_cast<int>(enemies.size()) is used to avoid comparison between signed and unsigned integers. (size_t is unsigned, int is signed)!!!
				std::cin.clear(); // clear the error flag
				std::cin.ignore(10000, '\n'); // discard invalid input
				std::cout << RED << "Invalid input. Please enter a valid enemy number: " << RESET;
				continue; // prompt for input again
			}
			std::cin.clear();
			std::cin.ignore(10000, '\n'); // discard any remaining input (such as newline characters, extra characters after the number (like 1xyz), etc.)
			break; // valid input, exit the loop
		}

		std::cout << CYAN << "------------------------------------------------------\n" << RESET;
		std::cout << YELLOW <<"          * You selected: " << enemies[enemy_choice - 1]->getName() << " as enemy! *" << RESET << std::endl;
		std::cout << CYAN << "------------------------------------------------------\n\n\n" << RESET;
		Character* player = heroes[hero_choice - 1];
		Character* enemy = enemies[enemy_choice - 1];
		std::cout << YELLOW << "Would you like to use an ability?" << RESET << std::endl;
		std::cout << CYAN << "------------------------------------------------------\n" << RESET;
		std::cout << RED <<"[1]"<< RESET <<" Yes" << std::endl;
		std::cout << RED << "[2]" << RESET << " No " << std::endl;
		std::cout << CYAN << "------------------------------------------------------\n" << RESET;
		int want_ability;
		while (true) { // input validation!
			std::cout << GREEN <<  "Your choice is: " << RESET;
			std::cin >> want_ability;
			std::cout << '\n';
			if (std::cin.fail() || want_ability < 1 || want_ability > 2) { // static_cast<int>(heroes.size()) is used to avoid comparison between signed and unsigned integers. (size_t is unsigned, int is signed)!!!
				std::cin.clear(); // clear the error flag
				std::cin.ignore(10000, '\n'); // discard invalid input
				std::cout << RED << "Invalid input. Please enter a valid choice (1 for YES and 2 for NO): " << RESET;
				continue; // prompt for input again
			}
			std::cin.clear();
			std::cin.ignore(10000, '\n'); // discard any remaining input (such as newline characters, extra characters after the number (like 1xyz), etc.)
			break; // valid input, exit the loop
		}
		std::cout << CYAN << "------------------------------------------------------\n" << RESET;
		if (want_ability == 1 && !player->getAbilities().empty()) {
			player->showAbilities();
			std::cout << CYAN << "------------------------------------------------------\n" << RESET;
			std::cout << "Please select an " << CYAN << "ability " << RESET << "by entering the corresponding number, \n";
			int ability_choice;
			while (true) { // input validation!
				std::cout << GREEN << "Your choice is: " << RESET;
				std::cin >> ability_choice;
				if (std::cin.fail() || ability_choice < 1 || ability_choice > static_cast<int>(player->getAbilities().size())) { // static_cast<int>(player->getAbilities().size()) is used to avoid comparison between signed and unsigned integers. (size_t is unsigned, int is signed)!!!
					std::cin.clear(); // clear the error flag
					std::cin.ignore(10000, '\n'); // discard invalid input
					std::cout << RED << "Invalid input. Please enter a valid ability number: " << RESET;
					continue; // prompt for input again
				}
				std::cin.clear();
				std::cin.ignore(10000, '\n'); // discard any remaining input (such as newline characters, extra characters after the number (like 1xyz), etc.)
				break; // valid input, exit the loop
			}
			std::cout << std::endl;
			std::cout << RED << "------------------------------------------------------\n" << RESET;
			std::cout << RED << "               * FIGHT BEGINS! *            " << RESET << std::endl;
			std::cout << RED << "------------------------------------------------------\n" << RESET;
			Ability& selected_ability = player->getAbilities()[ability_choice - 1]; //reference to the selected ability!

			if (!player->isSpecialAbility(selected_ability) && selected_ability.type != Ability::PowerType::Offensive) {
				player->useAbility(selected_ability, enemy); // Use abilities in order.
				player->attack(enemy); // Attack the weakest hero
			}
			else if (!player->isSpecialAbility(selected_ability) && selected_ability.type == Ability::PowerType::Offensive) {
				player->useAbility(selected_ability, enemy); // Use abilities in order.
			}
			else if (selected_ability.name == "Rage") {
				player->rage(enemy);
			}
			else if (selected_ability.name == "Meteor") {
				player->meteor(enemies);
			}
			else if (selected_ability.name == "Heal Allies") {
				player->healAllies(heroes);
			}

			std::cout << RED << "------------------------------------------------------\n" << RESET;
			std::cout << RED << "                 * FIGHT ENDS! *            " << RESET << std::endl;
			std::cout << RED << "------------------------------------------------------\n" << RESET;
			std::cout << GREEN << "Press Enter to show round results..." << RESET;
			std::cin.get(); // VERY IMPORTANT: std::cin.get() should be used exaclty where the cout is skipped. (exactly at the end of the working part and before the part with problem to fix it)
			clearConsole();
		}
		else if (want_ability == 1 && player->getAbilities().empty()) {
			std::cout << std::endl;
			std::cout << RED << " >>> All " << CYAN << "abilities " << RED << "have been used." << RESET << std::endl;
			std::cout << std::endl;
			std::cout << RED << "------------------------------------------------------\n" << RESET;
			std::cout << RED << "               * FIGHT BEGINS! *            " << RESET << std::endl;
			std::cout << RED << "------------------------------------------------------\n" << RESET;
			player->attack(enemy);
			std::cout << RED << "------------------------------------------------------\n" << RESET;
			std::cout << RED << "                 * FIGHT ENDS! *            " << RESET << std::endl;
			std::cout << RED << "------------------------------------------------------\n" << RESET;
			std::cout << GREEN << "Press Enter to show round results..." << RESET;
			std::cin.get();
			clearConsole();
		}
		else{
			std::cout << RED << "------------------------------------------------------\n" << RESET;
			std::cout << RED << "               * FIGHT BEGINS! *            " << RESET << std::endl;
			std::cout << RED << "------------------------------------------------------\n" << RESET;
			player->attack(enemy);
			std::cout << RED << "------------------------------------------------------\n" << RESET;
			std::cout << RED << "                 * FIGHT ENDS! *            " << RESET << std::endl;
			std::cout << RED << "------------------------------------------------------\n" << RESET;
			std::cout << GREEN << "Press Enter to show round results..." << RESET;
			std::cin.get();
			clearConsole();
		}
		std::cout << '\n' << std::endl;
		showBattleStatus(player, enemy); // you stayed here, this function doesn't work?
	}

	void BattleSystem::enemyTurn() {
		int strongest = 0; // Initialize the index of the strongest enemy
		int weakest = 0; // Initialize the index of the weakest hero

		for (size_t i = 1; i < enemies.size(); i++) { // as .size() function returns unsigned integer, make 'i' size_t (unsigned).
			if (enemies[i]->getAttackPower() > enemies[strongest]->getAttackPower()) {
				strongest = static_cast<int>(i); //static_cast<int>(i) is used to prevent type mismatch! (type of size() function is unsigned integer (size_t)) 
			}
		}
		Character* enemy = enemies[strongest]; //strongest enemy choosed by AI

		for (size_t i = 1; i < heroes.size(); i++) {
			if (heroes[i]->getHealth() < heroes[weakest]->getHealth()) {
				weakest = static_cast<int>(i);
			}
		}
		Character* player = heroes[weakest]; //weakest hero choosed by AI
		std::cout << YELLOW << "\n===================== * ENEMY TURN * =====================\n" << RESET;
		std::cout << "Enemy selected its character: " << RED << enemy->getName() << RESET << "\n";
		std::cout << "Enemy selected target: " << RED << player->getName() << RESET << "\n";
		std::cout << YELLOW << "===========================================================\n" << RESET;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << RED << "------------------------------------------------------\n" << RESET;
		std::cout << RED << "               * FIGHT BEGINS! *            " << RESET << std::endl;
		std::cout << RED << "------------------------------------------------------\n" << RESET;
		if (!enemy->getAbilities().empty()) {
			Ability& selected_ability = enemy->getAbilities()[0]; //reference to the selected ability! (for make a change in first ability through selected_ability.)
			if (!enemy->isSpecialAbility(selected_ability) && selected_ability.type != Ability::PowerType::Offensive) {
				enemy->useAbility(selected_ability, player); // Use abilities in order.
				enemy->attack(player); // Attack the weakest hero
			}
			else if (!enemy->isSpecialAbility(selected_ability) && selected_ability.type == Ability::PowerType::Offensive) {
				enemy->useAbility(selected_ability, player); // Use abilities in order.
			}
			else if (selected_ability.name == "Empowered Poison Bite") {
				enemy->empoweredPoisonBite(heroes); // Attack the weakest hero by using only special ability for the boss.
			}
			else if (selected_ability.name == "Ground Slam") {
				enemy->groundSlam(heroes); // Attack the weakest hero by using only special ability for the boss.
			}
		}
		else {
			enemy->attack(player);
		}

		std::cout << RED << "------------------------------------------------------\n" << RESET;
		std::cout << RED << "                 * FIGHT ENDS! *            " << RESET << std::endl;
		std::cout << RED << "------------------------------------------------------\n" << RESET;
		std::cout << std::endl;
		std::cout << GREEN << "Press Enter to show round results..." << RESET;
		std::cin.get();
		clearConsole();
		std::cout << std::endl;
		showBattleStatus(player, enemy);
	}
}