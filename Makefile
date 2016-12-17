client:
	g++ \
		-std=c++1z \
        -Wall \
        src/core/*.cpp \
        src/math/*.cpp \
        src/input/*.cpp \
        src/client/*.cpp \
        src/network/*.cpp \
        src/graphics/*.cpp \
        src/planets-client.cpp \
		src/client/states/*.cpp \
        src/client/handlers/*.cpp \
        src/client/messages/*.cpp \
        -g \
        -o ./bin/planets \
        -lsfml-graphics -lsfml-system -lsfml-window -lsfml-network \

server:
	g++ \
		-std=c++1z \
        -Wall \
        src/core/*.cpp \
        src/math/*.cpp \
        src/input/*.cpp \
        src/server/*.cpp \
        src/network/*.cpp \
        src/planets-server.cpp \
        -o ./bin/planets-server \
        src/server/handlers/*.cpp \
        src/server/messages/*.cpp \
        -g \
        -lsfml-system -lsfml-window -lsfml-network \

all: client server
