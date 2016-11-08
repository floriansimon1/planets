VARS=-DSERVER_PORT=45001 -DBROADCAST_PORT=45002

client:
	g++ \
        -Wall \
        src/io/*.cpp \
        src/core/*.cpp \
        src/math/*.cpp \
        src/network/*.cpp \
        src/graphics/*.cpp \
        src/planets-client.cpp \
        -o ./bin/planets \
        -lsfml-graphics -lsfml-system -lsfml-window -lsfml-network \
        -g \
        ${VARS}

server:
	g++ \
        -Wall \
        src/io/*.cpp \
        src/core/*.cpp \
        src/math/*.cpp \
        src/planets-server.cpp \
        src/network/server.cpp \
        -o ./bin/planets-server \
        -lsfml-system -lsfml-window -lsfml-network \
        -g \
        ${VARS}

all: client server
