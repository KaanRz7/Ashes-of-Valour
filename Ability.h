#pragma once
#include <string>

namespace Game {
	struct Ability {
		enum class PowerType {
			Offensive,
			Defensive,
			Support,
			Special
		};
		std::string name;
		PowerType type;
		int amount;
		bool operator==(const Ability& other) const {
			return name == other.name && type == other.type && amount == other.amount; // VERY IMPORTANT!!: in struct class, we need to implement the operator== to compare two abilities, because we will use std::erase_if to remove the used ability from the vector of abilities in the Character class. If we don't implement this operator, std::erase_if will not be able to compare the abilities and will not remove the used ability from the vector. 
		}
	};
}