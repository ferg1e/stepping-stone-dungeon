#ifndef BASIC_SCENE_H
#define BASIC_SCENE_H

#include "Hero.h"
#include "Scene.h"
#include "SceneOption.h"
#include <string>
#include <vector>

struct BasicScene : Scene {
	std::string m_desc;
	std::vector<SceneOption> m_options;

	BasicScene(
		std::string desc = "",
		std::vector<SceneOption> options = {}
	)
		: m_desc {desc}
		, m_options {options}
	{}

	Scene* render(Hero* hero) override;
};

#endif

