#ifndef SCENE_OPTION_H
#define SCENE_OPTION_H

#include "Scene.h"
#include <string>

struct SceneOption {
	std::string label;
	Scene* next;
};

#endif

