#include "./serve-game.hpp"
#include "../messages/server-announcement.hpp"

ServeGame::ServeGame(): maxPlayers(5) {
}

void ServeGame::process(Application &application) {
    doProcess(static_cast<ServerApplication&>(application));
}

void ServeGame::doProcess(ServerApplication &application) {
    application.serverCommunicator.broadcast(ServerAnnouncement::getPacket(application));
}
