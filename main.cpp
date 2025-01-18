#include "BasicScene.h"
#include "Hero.h"
#include <iostream>

int main() {

	//
	Hero hero;

	//
	BasicScene about;
	BasicScene home {
		"Binary Dungeon Tree",
		{{"About", &about}}
	};

	about.desc = "about blurb here";
	about.options = {{"Back", &home}};

	//
	Scene* next_scene = &home;

	//
	while(next_scene != nullptr) {
		next_scene = next_scene->render(&hero);
	}

	//
	std::cout << "game while loop exited, uh oh" << std::endl;

	//
	return 0;
}

