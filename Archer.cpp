#include "Archer.h"
#include "Ability.h"
#include <string>
#include <vector>
namespace Game {
	Archer::Archer(const std::string& name)
		: Character{ name, 80, 25, 15 } {
		// Initialize abilities for the Archer
		abilities.push_back({ "Precise Shot", Ability::PowerType::Offensive, 25 });
		abilities.push_back({ "Evasion", Ability::PowerType::Defensive, 20 });
		abilities.push_back({ "Heal Arrow", Ability::PowerType::Support, 20 });
	}
}