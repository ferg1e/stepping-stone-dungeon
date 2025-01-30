#ifndef HERO_H
#define HERO_H

#include <string>

struct Hero {
	std::string type;
	int maxHp;
	int currHp;
	int speed;
	int strength;
};

#endif

