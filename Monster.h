#ifndef MONSTER_H
#define MONSTER_H

#include <string>

struct Monster {
	std::string type;
	int maxHp;
	int currHp;
	int speed;
	int strength;
};

#endif

