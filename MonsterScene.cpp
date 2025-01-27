#include "functions.h"
#include <iostream>
#include "MonsterScene.h"

Scene* MonsterScene::render(Hero* hero) {
	clearScreen();

	for(Monster m : monsters) {
		std::cout << m.type << std::endl;
	}

	return nullptr;
}

