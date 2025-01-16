#include "functions.h"
#include <iostream>

void clearScreen() {
	system("clear");
}

void clearLines(int count) {
	while(count-- > 0) {
		std::cout << "\x1b[1F" << "\x1b[2K";
	}
}

