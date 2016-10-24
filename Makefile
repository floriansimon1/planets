all:
	g++ -o -Wall src/planets.cpp src/graphics/renderer.cpp -o ./bin/planets -lsfml-graphics -lsfml-system -lsfml-window
