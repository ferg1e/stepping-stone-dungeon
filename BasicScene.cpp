#include "BasicScene.h"
#include <iostream>

Scene* BasicScene::render(Hero* hero) {
	std::cout << desc << std::endl << std::endl;

	for(SceneOption o : options) {
		std::cout
			<< "["
			<< o.label.substr(0, 1)
			<< "]"
			<< o.label.substr(1)
			<< std::endl;
	}

	return nullptr;
}

