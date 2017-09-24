#include "discordclient.hpp"

Discord::Discord(Token token) : Discord(Gateway::JSON, token) {
}
Discord::Discord(Gateway::Type type, Token token) : _type(type), _gateway(type),  _token(token) {
}

int Discord::work() {
    while (!ended) {
        // handles gateway events
    }
    return exit_status;
}
