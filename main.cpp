#include <iostream>
#include <string>

int main() {
    std::string action;

    std::cout
        << "Choose your character:"
        << std::endl
        << "[K]night"
        << std::endl
        << "[A]ssassin"
        << std::endl;

    getline(std::cin, action);

    if(action == "K" || action == "k") {
        std::cout << "Knight!" << std::endl;
    }
    else if(action == "A" || action == "a") {
        std::cout << "Assassin!" << std::endl;
    }
    else {
        std::cout << "Unknown character" << std::endl;
        return 1;
    }

    std::cout << "End of Game..." << std::endl;
    return 0;
}

