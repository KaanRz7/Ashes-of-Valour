#include "GameManager.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cstdlib>

namespace Game {
	GameManager::GameManager(RoundSystem& m_roundEngine) : m_roundEngine(m_roundEngine) {}
	void GameManager::printWelcomeMessage() const {

		std::cout << CYAN << "==================================================\n" << RESET;
		std::cout << YELLOW << "        * WELCOME TO ASHES OF VALOUR *          \n" << RESET;
		std::cout << CYAN << "==================================================\n" << RESET;

		std::cout << WHITE << " Darkness has fallen upon the realm of Valour...\n"
			<< " Only those with unwavering courage can break the curse!\n\n" << RESET;

		std::cout << GREEN << ">> Prepare yourself, Champion. Your journey begins now...\n\n" << RESET;
		std::cout << RED << "* NOTE: You must create at least one hero and one enemy to start battle!\n" << RESET;
		std::cout << YELLOW << "* NOTICE: PLEASE PLAY IN FULLSCREEN MODE! * \n\n" << RESET;
		std::cout << RED << "* [IMPORTANT]: " << RESET << "Please check the " << YELLOW << "How to Play " << RESET << "section before starting.\n";
		std::cout << GREEN << "* [TIP]: " << RESET <<"If the screen jumped, scroll up slightly to review.\n" << RESET;
		std::cout << CYAN << "==================================================\n\n" << RESET;
	}

	void GameManager::startGame() {
		clearConsole(); 
		printWelcomeMessage();
		std::cout << GREEN <<"\nPress Enter to begin your journey..." << RESET ;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin.get(); 
		m_roundEngine.startRound();
	}
	void GameManager::mainMenu() {

		while (true) {
			std::cout << "\n\n" << CYAN;
			std::cout << "\t\t=======================================================================\n";
			std::cout << YELLOW << "\t\t                        AA       OOOOOOO   VV      VV               \n";
			std::cout << "\t\t                       A  A     OOO   OOO   VV    VV                \n";
			std::cout << "\t\t                      AAAAAA    OOO   OOO    VV  VV                 \n";
			std::cout << "\t\t                     A     A     OOO   OOO     VVV                  \n";
			std::cout << "\t\t                    A       A     OOOOOOO      VV                   \n" << RESET;
			std::cout << CYAN << "\t\t=======================================================================\n";
			std::cout << "\t\t                    * A S H E S   O F   V A L O U R *                     \n";
			std::cout << "\t\t=======================================================================\n\n" << RESET;
			

			std::cout << "\t\t           " << GREEN << "               PRESS ENTER TO START..." << RESET << "\n";
			std::cout << "\t\t      " << YELLOW << "        ( For the best experience, play in full screen )" << RESET << "\n";
			std::cout << RED << "\t\t\t\t        ~ Made By Kaan Tanriverdi ~ " << RESET << std::endl;

			std::cin.get();
			clearConsole();
			std::cout << CYAN << "\n";
			std::cout << "          ===============================================================\n";
			std::cout << "          ||                                                           ||\n";
			std::cout << "          ||            ~  A S H E S   O F   V A L O U R  ~            ||\n";
			std::cout << "          ||                                                           ||\n";
			std::cout << "          ===============================================================\n" << RESET;

			std::cout << YELLOW << "                    [1] " << WHITE << "Start New Game\n";
			std::cout << YELLOW << "                    [2] " << WHITE << "How to Play " << YELLOW << "(Recommended)\n" << RESET;

			std::cout << CYAN << "                    [3] " << WHITE << "Version & Patch Notes\n";
			std::cout << CYAN << "                    [4] " << WHITE << "Future Improvements\n";

			std::cout << RED << "                    [5] " << WHITE << "Exit Game\n";

			std::cout << CYAN << "          ===============================================================\n" << RESET;
			std::cout << GREEN << "                              >>> Your Choice: " << RESET;
			int choice;
			std::cin >> choice;
			while (std::cin.fail() || choice < 1 || choice > 5) {
				std::cin.clear(); // clear the error flag
				std::cin.ignore(10000, '\n'); // discard invalid input
				std::cout << RED << "Invalid input. Please enter a valid choice (1-5): " << RESET;
				std::cin >> choice;
			}
			switch (choice) {
			case 1:
			{
				clearConsole();
				startGame();
				break;
			}
			case 2:
			{
				clearConsole();
				std::cout << CYAN << "=========================================================================================================================\n" << RESET;
				std::cout << YELLOW << "                                        * ASHES OF VALOUR - HOW TO PLAY ? *       \n" << RESET;
				std::cout << CYAN << "========================================================================================================================\n\n" << RESET;

				std::cout << GREEN << "[ OBJECTIVE ]\n" << RESET;
				std::cout << " Create your team of Heroes and set up the Enemy party.\n";
				std::cout << " Outsmart the Enemy AI in tactical turn-based combat! (" << YELLOW << "first round belongs to player :)" << RESET << ")\n\n";

				std::cout << GREEN << "[ COMBAT RULES & ABILITY MECHANICS ]\n" << RESET;
				std::cout << " " << CYAN << "1." << RESET << " Setup Phase  : Choose and create both Heroes and Enemies.\n";
				std::cout << " " << CYAN << "2." << RESET << " Turn Order   : Units take turns based on the round system.\n";
				std::cout << " " << CYAN << "3." << RESET << " Ability Pool : Standart Abilities are limited and used according to their defined amounts.\n";
				std::cout << "                 Once your ability pool empties, you automatically fall back to standard attacks.\n";
				std::cout << " " << CYAN << "4." << RESET << " Enemy AI     : Enemies will automatically target and attack your team.\n";
				std::cout << " " << CYAN << "5." << RESET << " Victory      : Wipe out all enemies to claim victory!\n\n";

				std::cout << GREEN << "[ SPECIAL ABILITIES DIRECTORY ]\n" << RESET;
				std::cout << " " << YELLOW << "* Warrior (Rage):" << RESET << " Heals self for 20 HP and deals 35 damage.\n";
				std::cout << " " << YELLOW << "* Mage (Meteor):" << RESET << " Deals 35 AoE damage to all enemies.\n";
				std::cout << " " << YELLOW << "* Mage (Heal Allies):" << RESET << " Restores 25 HP to all allies.\n";
				std::cout << " " << RED << "* Elite Enemy (Empowered Poison Bite):" << RESET << " Creates a toxic cloud dealing 25 damage to all heroes.\n";
				std::cout << " " << RED << "* Boss (Ground Slam):" << RESET << " Shakes the ground, dealing 50 damage to all heroes.\n\n";

				std::cout << GREEN << "[ TACTICAL TIPS ]\n" << RESET;
				std::cout << " " << RED << "-" << RESET << " Time your Hero Abilities wisely for maximum effect.\n";
				std::cout << " " << RED << "-" << RESET << " Balance your team composition against the Enemy setup. (" << YELLOW << "or fantasy-style scenarios might be tried =)" << RESET << ")\n\n";

				std::cout << "\t\t      " << YELLOW << "( For the best experience, play in full screen )" << RESET << "\n";
				std::cout << GREEN << "\t \t"<<"  [TIP]: " << RESET << "If the screen jumped, scroll up slightly to review.\n" << RESET;

				std::cout << CYAN << "========================================================================================================================\n\n" << RESET;
				break;
			}case 3:
			{
				clearConsole();
				std::cout << CYAN << "======================================================\n" << RESET;
				std::cout << YELLOW << "         ASHES OF VALOUR - VERSION PITCH NOTES        \n" << RESET;
				std::cout << "                      " << GREEN << "[ v1.0.0 ]                      \n" << RESET;
				std::cout << CYAN << "======================================================\n\n" << RESET;

				std::cout << GREEN << "* Decoupled C++ Architecture:" << RESET << " Modular design with clean separation\n";
				std::cout << "  between UI, game loop, and combat memory management.\n\n";

				std::cout << GREEN << "* Custom Tactical Combat:" << RESET << " Full freedom to set up both Hero and Enemy\n";
				std::cout << "  parties, featuring strategic abilities against adaptive AI.\n\n";

				std::cout << GREEN << "* Dev Note:" << RESET << " Built with pure C++, zero external libraries, and unhealthy\n";
				std::cout << "  amounts of caffeine. If it compiles on the first try, please don't touch\n";
				std::cout << "  anything... just back away slowly " << YELLOW << "=))\n\n" << RESET;

				std::cout << RED << "\t       ~ Made By Kaan Tanriverdi ~ " << RESET << std::endl;
				std::cout << CYAN << "======================================================\n\n" << RESET;
				break;
			}case 4:
			{
				clearConsole();
				std::cout << CYAN << "======================================================\n" << RESET;
				std::cout << YELLOW << "            ASHES OF VALOUR - FUTURE ROADMAP          \n" << RESET;
				std::cout << CYAN << "======================================================\n\n" << RESET;

				std::cout << GREEN << "* Inventory & Item System:\n" << RESET;
				std::cout << "  Consumable items (potions, scrolls) and equippable gear\n";
				std::cout << "  to add deeper tactical layers to hero management.\n\n";

				std::cout << GREEN << "* Dynamic Round-Based Stat Scaling:\n" << RESET;
				std::cout << "  Adaptive HP, Attack, and Defense modifiers that evolve\n";
				std::cout << "  dynamically based on round progression and battle status.\n\n";

				std::cout << GREEN << "* Resource & Mana Management:\n" << RESET;
				std::cout << "  A full-fledged Mana/Energy system for high-tier Hero\n";
				std::cout << "  abilities to balance cooldowns and skill usage.\n\n";

				std::cout << GREEN << "* Level & Coin System\n" << RESET;
				std::cout << "  A basic single-player mode includes a level system\n";
				std::cout << "  and a coin system to gain coins per level and get items\n\n";

				std::cout << CYAN << "------------------------------------------------------\n" << RESET;
				std::cout << RED << "Note:" << RESET << " More features will be added as new creative ideas\n";
				std::cout << "      (or absurd gameplay mechanics) come to mind " << YELLOW << "=))\n" << RESET;
				std::cout << CYAN << "======================================================\n\n" << RESET;
				break;
			}
			case 5:
			{
				// Exit Game
				exit(0);
			}
			}
			std::cout << "\n";
			int subChoice;
			std::cout << CYAN << "========================================\n"
				<< "       *  ASHES OF VALOUR RPG  *      \n"
				<< "========================================\n" << RESET;
			std::cout << YELLOW << "  [1] " << WHITE << "Back to main menu\n";
			std::cout << YELLOW << "  [2] " << WHITE << "Exit Game\n";
			std::cout << CYAN << "========================================\n" << RESET;
			std::cout << GREEN << "Your Choice: " << RESET;
			std::cin >> subChoice;
			while (std::cin.fail() || subChoice < 1 || subChoice > 2) {
				std::cin.clear(); // clear the error flag
				std::cin.ignore(10000, '\n'); // discard invalid input
				std::cout << RED << "Invalid input. Please enter a valid choice (1-2): " << RESET;
				std::cin >> subChoice;
			}
			switch (subChoice) {
			case 1:
			{

				continue; // Go back to main menu	
			}
			case 2:
			{
				exit(0);
			}
			}
		}
	}
}