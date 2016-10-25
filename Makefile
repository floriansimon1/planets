all:
	g++ -o -Wall src/planets.cpp src/graphics/*.cpp src/core/*.cpp -o ./bin/planets -lsfml-graphics -lsfml-system -lsfml-window
