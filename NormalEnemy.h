#pragma once
#include "Enemy.h"
#include <string>
#include <vector>

class Character; // Forward declaration of Character class!!!!!!
namespace Game {
	class NormalEnemy : public Enemy {
	public:
		explicit NormalEnemy(const std::string& name); // "explicit" constructor to initialize a NormalEnemy with a name and default stats (explicit for single argument constructor to avoid implicit conversions)
	};
}