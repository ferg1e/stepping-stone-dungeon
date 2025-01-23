#include "BasicScene.h"
#include "Hero.h"
#include "NewGameScene.h"
#include <iostream>

int main() {

	//
	Hero hero;

	//
	BasicScene about;

	NewGameScene newGame {
		"new game desc",
		nullptr
	};

	BasicScene home {
		"Stepping Stone Dungeon",
		{
			{"New Game", &newGame},
			{"About", &about}
		}
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
	return 0;
}

