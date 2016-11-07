all:
	g++ \
        -Wall \
        src/io/*.cpp \
        src/core/*.cpp \
        src/math/*.cpp \
        src/planets.cpp \
        src/graphics/*.cpp \
        -o ./bin/planets \
        -lsfml-graphics -lsfml-system -lsfml-window \
        -g
