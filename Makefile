VARS=-DSERVER_PORT=45001 -DBROADCAST_PORT=45002

client:
	g++ \
        -Wall \
        src/core/*.cpp \
        src/math/*.cpp \
        src/input/*.cpp \
        src/client/*.cpp \
        src/network/*.cpp \
        src/graphics/*.cpp \
        src/planets-client.cpp \
        src/client/messages/*.cpp \
        -o ./bin/planets \
        -lsfml-graphics -lsfml-system -lsfml-window -lsfml-network \
        ${VARS}

server:
	g++ \
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
        ${VARS}

all: client server
