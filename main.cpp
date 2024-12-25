#include <cstdlib>
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

void room1End(Character& hero) {
    std::cout
        << "Room 1" << std::endl
        << "You chose the "
        << hero.type << "." << std::endl
        << "Where to next?" << std::endl
        << "[L]eft Door (Room 2)" << std::endl
        << "[R]ight Door (Room 3)" << std::endl;
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

    getline(std::cin, action);

    clearScreen();

    Character hero;

    if(action == "K" || action == "k") {
        hero.type = "Knight";
        hero.strength = 10;
        hero.speed = 5;
        hero.hp = 20;
        room1End(hero);
    }
    else if(action == "A" || action == "a") {
        hero.type = "Assassin";
        hero.strength = 5;
        hero.speed = 10;
        hero.hp = 20;
        room1End(hero);
    }
    else {
        std::cout << "Unknown character" << std::endl;
        std::exit(EXIT_FAILURE);
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
    clearScreen();
    home();

    std::cout << "End of Game..." << std::endl;
    return 0;
}

