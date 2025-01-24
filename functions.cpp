#include <algorithm>
#include <cctype>
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

std::string strToLower(std::string s) {
	std::transform(
		s.begin(),
		s.end(),
		s.begin(),
		[](unsigned char c) {
			return std::tolower(c);
		}
	);

	return s;
}

