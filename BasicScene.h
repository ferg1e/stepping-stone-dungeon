#ifndef BASIC_SCENE_H
#define BASIC_SCENE_H

#include "Hero.h"
#include "Scene.h"
#include "SceneOption.h"
#include <string>
#include <vector>

struct BasicScene : Scene {
	std::string desc;
	std::vector<SceneOption> options;

	BasicScene(
		std::string c_desc = "",
		std::vector<SceneOption> c_options = {}
	)
		: desc {c_desc}
		, options {c_options}
	{}

	Scene* render(Hero* hero) override;
};

#endif

