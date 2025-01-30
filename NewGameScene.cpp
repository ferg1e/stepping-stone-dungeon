#include <array>
#include "Hero.h"
#include "functions.h"
#include <iostream>
#include "NewGameScene.h"
#include <string>

Scene* NewGameScene::render(Hero* hero) {
	clearScreen();
	std::cout << desc << std::endl << std::endl;

	std::array<Hero, 1> heros {
		{"Knight", 10, 10, 6, 3}
	};

	for(Hero h : heros) {
		std::cout
			<< "["
			<< h.type.substr(0, 1)
			<< "]"
			<< h.type.substr(1)
			<< std::endl;
	}

	std::string action;

	while(true) {
		getline(std::cin, action);
		clearLines(1);

		for(Hero h : heros) {
			if(strToLower(action) == strToLower(h.type.substr(0, 1))) {
				*hero = h;
				return next;
			}
		}
	}
}

