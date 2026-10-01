#include "RoundSystem.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <vector>

namespace Game {
		RoundSystem::RoundSystem(BattleSystem& battleEngine) : battleEngine(battleEngine) {
		}
		void RoundSystem::startRound() {
			battleEngine.createCharacters();// Call the createCharacters function from BattleSystem (first things is creating the characters, then start the battle)
			auto& heroes = battleEngine.getHeroes(); // define heroes and enemies once more (by using battleEngine instance, assigning these created vectors) so that can be used as heroes and enemies after creation in createCharacters function.
			auto& enemies = battleEngine.getEnemies(); // IMPORTANT!!!!: In here, auto will automatically deduce the type of heroes and enemies as std::vector<Character*>&, which is a reference to the vector of Character pointers. Also, we use & for prevent copying the vector but giving a reference to the original vector, so that we can modify the original vector by using reference.
			for (int round = 1; !heroes.empty() && !enemies.empty(); ++round) {
				clearConsole();
				std::cout << '\n';
				if (round % 2 == 1) {
					std::cout << CYAN << "================================================= * ROUND " << round << CYAN << " BEGINS! * ======================================================" << RESET << std::endl;
					battleEngine.playerTurn();
					endRound(heroes, enemies);
					std::cout << CYAN << "================================================= * ROUND " << round << CYAN << " ENDS! * =======================================================" << RESET << std::endl;
					std::cout << GREEN << "Press Enter to continue next round..." << RESET;
					std::cin.get(); //to fix buffer problem again, at the end of the if!
					// Call the playerTurn function from BattleSystem
				}
				else {
					std::cout << CYAN << "\n================================================= * ROUND " << round << CYAN << " BEGINS! * =====================================================" << RESET << std::endl;
					battleEngine.enemyTurn();
					endRound(heroes, enemies);
					std::cout << CYAN << "================================================= * ROUND " << round << CYAN << " ENDS! * =======================================================" << RESET << std::endl;
					std::cout << GREEN << "Press Enter to continue next round..." << RESET;
					std::cin.get(); // std::cin.get() used for get one random key as input (used for press enter to continue etc...)	
					// Call the enemyTurn function from BattleSystem
				}
			}
			//decider function to check if the heroes or enemies are defeated, and display the winner.
			clearConsole();
			checkBattleStatus(heroes, enemies);
		}
		// Implementation for ending a round, such as checking for defeated characters and deleting them with their pointers, updating status, etc.

		void RoundSystem::endRound(std::vector<Character*>& heroes, std::vector<Character*>& enemies) {
			for (auto it = heroes.begin(); it != heroes.end();) { // initiliaze and test part of the for loop is done in the same line, but the increment part is done in the else statement, because we are erasing the element from the vector and we need to update the iterator to point to the next element after erasing.
				if ((*it)->getHealth() <= 0) {
					std::cout << RED << "========================================================================\n"
						<< "          >>> FATALITY: " << RESET << CYAN << (*it)->getName() << RESET << " vanquished from the realm! "<< RED << "<<<\n"
						<< "========================================================================" << RESET << "\n" << std::endl;
					delete* it; // Free the memory allocated for the defeated hero (previously delete *it then the adress from the vector!!!)
					it = heroes.erase(it); // Remove defeated hero from the vector
				}
				else {
					++it;
				}
			}
			for (auto it = enemies.begin(); it != enemies.end();) {
				if ((*it)->getHealth() <= 0) {
					std::cout << RED << "========================================================================\n"
						<< "          >>> FATALITY: " << RESET << CYAN << (*it)->getName() << RESET << " vanquished from the realm! " << RED << "<<<\n"
						<< "========================================================================" << RESET << "\n" << std::endl;
					delete* it;
					it = enemies.erase(it); // Remove defeated enemy from the vector
				}
				else {
					++it; // adress will be uptated for 8 bytes, because the pointer is 8 bytes in 64 bit systems, so the iterator will point to the next element in the vector. (c++ automatically handles the memory management for the vector, so we don't need to worry about it.)
				}
			}
		}

		bool RoundSystem::checkBattleStatus(const std::vector<Character*>& heroes, const std::vector<Character*>& enemies) {
			if (heroes.empty() && enemies.empty()) {
				std::cout << "\n\n"<< YELLOW;
				std::cout << "\t\t======================================================\n";
				std::cout << "\t\t         ~ MUTUAL DESTRUCTION! IT'S A DRAW! ~              \n";
				std::cout << "\t\t======================================================\n\n"<<RESET;
				return true;
			}
			if (heroes.empty()) {
				std::cout << "\n\n"<<RED;
				std::cout << "\t\t======================================================\n";
				std::cout << "\t\t   YYYYY   YYYYY   OOOOOOO   UUU   UUU     \n";
				std::cout << "\t\t    YYYY   YYYY   OOO   OOO  UUU   UUU     \n";
				std::cout << "\t\t     YYYY YYYY    OOO   OOO  UUU   UUU     \n";
				std::cout << "\t\t      YYYYYYY     OOO   OOO  UUU   UUU     \n";
				std::cout << "\t\t       YYYYY       OOOOOOO    UUUUUUU      \n";
				std::cout << "\t\t======================================================\n";
				std::cout << "\t\t  LLLL        OOOOOOO     SSSSSS   EEEEEEEE \n";
				std::cout << "\t\t  LLLL       OOO   OOO   SSSS  SS  EEEE     \n";
				std::cout << "\t\t  LLLL       OOO   OOO    SSSSSS   EEEEEEEE \n";
				std::cout << "\t\t  LLLL       OOO   OOO   SS  SSSS  EEEE     \n";
				std::cout << "\t\t  LLLLLLLLLL  OOOOOOO     SSSSSS   EEEEEEEE \n";
				std::cout << "\t\t======================================================\n";
				std::cout << "\t\t          ~ ALL HEROES HAVE BEEN DEFEATED! ~        \n";
				std::cout << "\t\t======================================================\n\n" << RESET;
				return true;
			}
			if (enemies.empty()) {
				std::cout << "\n\n"<< CYAN;
				std::cout << "\t\t=====================================================================\n";
				std::cout << "\t\t VV      VV  IIIIII   CCCCCC  TTTTTTTT   OOOOOOO  RRRRRRR   YY    YY \n";
				std::cout << "\t\t  VV    VV     II    CC   CC     TT     OOO   OOO RR   RRR   YYYYYY  \n";
				std::cout << "\t\t   VV  VV      II    CC          TT     OOO   OOO RRRRRRR     YYYY   \n";
				std::cout << "\t\t    VVVV       II    CC   CC     TT     OOO   OOO RR  RRR      YY    \n";
				std::cout << "\t\t     VV      IIIIII   CCCCCC     TT      OOOOOOO  RR   RRR     YY    \n";
				std::cout << "\t\t=====================================================================\n";
				std::cout << "\t\t                  ~ ALL ENEMIES HAVE BEEN DEFEATED! ~        \n";
				std::cout << "\t\t=====================================================================\n\n"<< RESET;
				return true;
			}
			return false;
		}
}