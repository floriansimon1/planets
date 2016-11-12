VARS=-DSERVER_PORT=45001 -DBROADCAST_PORT=45002

client:
	g++ \
        -Wall \
        src/io/*.cpp \
        src/core/*.cpp \
        src/math/*.cpp \
        src/client/*.cpp \
        src/network/*.cpp \
        src/graphics/*.cpp \
        src/planets-client.cpp \
        -o ./bin/planets \
        -lsfml-graphics -lsfml-system -lsfml-window -lsfml-network \
        ${VARS}

server:
	g++ \
        -Wall \
        src/io/*.cpp \
        src/core/*.cpp \
        src/math/*.cpp \
        src/server/*.cpp \
        src/network/*.cpp \
        src/planets-server.cpp \
        -o ./bin/planets-server \
        -g \
        -lsfml-system -lsfml-window -lsfml-network \
        ${VARS}

all: client server
