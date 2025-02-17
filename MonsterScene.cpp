#include <chrono>
#include "functions.h"
#include <iostream>
#include "MonsterScene.h"
#include <thread>
#include <vector>

Scene* MonsterScene::render(Hero* hero) {
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
		clearScreen();

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

			std::string action;

			while(true) {
				getline(std::cin, action);
				clearLines(1);

				//
				int actionInt {0};

				try {
					actionInt = std::stoi(action);
				}
				catch(...) {}

				//
				bool isActionOkay = actionInt > 0
					&& actionInt <= monsters.size();

				if(isActionOkay) {
					--monsters[actionInt - 1].currHp;
					isStillFighting = !isAllMonstersDead();
					break;
				}
			}
		}
		else {

			//
			std::cout
				<< "It's the bat's turn"
				<< std::endl;

			std::this_thread::sleep_for(std::chrono::milliseconds(1500));

			std::cout
				<< "Bat attacks hero"
				<< std::endl;
			--hero->currHp;

			//
			if(hero->currHp <= 0) {
				isStillFighting = false;
			}

			//
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		}

		//
		++currTurn;

		if(currTurn == turnOrder.size()) {
			currTurn = 0;
		}
	}

	return nullptr;
}

bool MonsterScene::isAllMonstersDead() {
	for(Monster m : monsters) {
		if(m.currHp > 0) {
			return false;
		}
	}

	return true;
}

