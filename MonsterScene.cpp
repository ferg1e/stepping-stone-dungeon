#include "functions.h"
#include <iostream>
#include "MonsterScene.h"
#include <vector>

Scene* MonsterScene::render(Hero* hero) {
	clearScreen();

	/*
	- turn order for hero and monsters.
	- 0 = hero.
	- all other numbers = a monster.
	- the monster numbers are an index into
	the monsters vector, but you need to
	subtract one.
	- this turn order keeps repeating.
	*/
	std::vector<int> turnOrder {0, 1};

	//index into turnOrder vector
	int currTurn {0};

	//
	bool isStillFighting {true};

	//
	while(isStillFighting) {
		for(Monster m : monsters) {
			std::cout
				<< m.type
				<< " (" << m.currHp << "/"
				<< m.maxHp << ")"
				<< std::endl;
		}

		std::cout
			<< std::endl
			<< hero->type
			<< " (" << hero->currHp << "/"
			<< hero->maxHp << ")"
			<< std::endl << std::endl;

		//
		int whoseTurn = turnOrder.at(currTurn);
		bool isHerosTurn = whoseTurn == 0;

		//
		if(isHerosTurn) {
			int mCount = 1;

			for(Monster m : monsters) {
				std::cout
					<< "[" << mCount << "]"
					<< " Attack "
					<< m.type
					<< std::endl;

				++mCount;
			}
		}

		//
		++currTurn;
		isStillFighting = false;
	}

	return nullptr;
}

