#ifndef SCENE_H
#define SCENE_H

#include "Hero.h"

struct Scene {
	virtual Scene* render(Hero* hero) = 0;
};

#endif

