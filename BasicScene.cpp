#include "BasicScene.h"
#include "functions.h"
#include <iostream>
#include <string>

Scene* BasicScene::render(Hero* hero) {
	clearScreen();
	std::cout << desc << std::endl << std::endl;

	for(SceneOption o : options) {
		std::cout
			<< "["
			<< o.label.substr(0, 1)
			<< "]"
			<< o.label.substr(1)
			<< std::endl;
	}

	std::string action;

	while(true) {
		getline(std::cin, action);
		clearLines(1);

		for(SceneOption o : options) {
			if(action == o.label.substr(0, 1)) {
				return o.next;
			}
		}
	}
}

