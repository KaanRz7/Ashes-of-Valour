#include "NormalEnemy.h"
#include "Ability.h"
#include <string>
#include <vector>
namespace Game {
	NormalEnemy::NormalEnemy(const std::string& name)
		: Enemy{ name, 80, 15, 5 } {
		// Initialize abilities for the NormalEnemy
		abilities.push_back({ "Poison Bite", Ability::PowerType::Offensive, 15 });
	}
}