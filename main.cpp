#include "BasicScene.h"
#include <cstdlib>
#include "Hero.h"
#include <iostream>
#include <string>

void home();
void newGame();
void about();

struct Character {
    std::string type;
    int strength;
    int speed;
    int hp;
};

void clearScreen() {
    system("clear");
}

void clearLines(int count) {
    while(count-- > 0) {
        std::cout << "\x1b[1F" << "\x1b[2K";
    }
}

void room1a() {
    std::cout
        << "<Room 1>" << std::endl
        << "You enter the dungeon and hear a dripping noise. In the half darkness you make out a passageway straight ahead and stairs off to the left. Which way do you want to go?" << std::endl
        << "[P]assageway" << std::endl
        << "[S]tairs" << std::endl; 
}

void home() {
    std::string action;

    std::cout
        << "Binary Dungeon Tree" << std::endl
        << "[N]ew Game" << std::endl
        << "[A]bout" << std::endl;

    getline(std::cin, action);

    clearScreen();

    if(action == "N" || action == "n") {
        newGame();
    }
    else if(action == "A" || action == "a") {
        about();
    }
    else {
        std::cout << "Invalid option" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void newGame() {
    std::string action;

    std::cout
        << "Choose your character:"
        << std::endl
        << "[K]night"
        << std::endl
        << "[A]ssassin"
        << std::endl;

    bool isKnight {false};
    bool isAssassin {false};

    getline(std::cin, action);

    isKnight = action == "K" || action == "k";
    isAssassin = action == "A" || action == "a";

    clearScreen();

    if(!isKnight && !isAssassin) {
        std::cout
            << "invalid option"
            << std::endl;

        std::exit(EXIT_FAILURE);
    }

    Character hero;

    if(isKnight) {
        hero.type = "Knight";
        hero.strength = 10;
        hero.speed = 5;
        hero.hp = 20;
    }
    else {
        hero.type = "Assassin";
        hero.strength = 5;
        hero.speed = 10;
        hero.hp = 20;
    }

    std::cout
        << "You chose the "
        << hero.type << "." << std::endl
        << "[E]nter the Dungeon" << std::endl
        << "[O]ops, change character" << std::endl;

    bool isEnter {false};
    bool isOops {false};

    while(!isEnter && !isOops) {
        getline(std::cin, action);
        isEnter = action == "E" || action == "e";
        isOops = action == "O" || action == "o";
        clearLines(1);
    }

    clearScreen();

    if(isEnter) {
        room1a();
    }
    else {
        newGame();
    }
}

void about() {
    std::cout << "Binary Dungeon Tree is a text-based dungeon crawler. The dungeon is shaped like a binary tree with each node being a room. The root room (room 1) is where you select your character. From there you can take the left door to go down to room 2, or the right door to go down to room 3. Room 2 leads to room 4 or 5, and room 3 leads to room 6 or 7. So on and so forth. Each room besides room 1 is either a monster, a shop or a warp zone." << std::endl << std::endl << "[B]ack" << std::endl;

    std::string action;

    while(action != "B" && action != "b") {
        getline(std::cin, action);
        clearLines(1);
    }

    clearScreen();
    home();
}

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

