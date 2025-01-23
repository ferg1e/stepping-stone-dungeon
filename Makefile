# always run this when make is called
always:
	g++ -std=c++14 -o game main.cpp BasicScene.cpp NewGameScene.cpp functions.cpp

