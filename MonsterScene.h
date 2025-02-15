#ifndef MONSTER_SCENE_H
#define MONSTER_SCENE_H

#include "Hero.h"
#include "Monster.h"
#include "Scene.h"
#include <vector>

struct MonsterScene : Scene {
	std::vector<Monster> monsters;

	MonsterScene(
		std::vector<Monster> c_monsters = {}
	)
		: monsters {c_monsters}
	{}

	Scene* render(Hero* hero) override;

private:
	bool isAllMonstersDead();
};

#endif

