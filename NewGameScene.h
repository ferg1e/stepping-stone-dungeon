#ifndef NEW_GAME_SCENE_H
#define NEW_GAME_SCENE_H

#include "Hero.h"
#include "Scene.h"
#include <string>

struct NewGameScene : Scene {
	std::string desc;
	Scene* next;

	NewGameScene(
		std::string c_desc = "",
		Scene* c_next = {}
	)
		: desc {c_desc}
		, next {c_next}
	{}

	Scene* render(Hero* hero) override;
};

#endif

