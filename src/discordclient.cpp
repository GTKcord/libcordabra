#include "discordclient.hpp"

Discord::Discord(Token token, GatewayType type, std::string apiPrefix)
: _type(type), _gateway(this, _type), _endpoints(apiPrefix), _token(token) {
}

int Discord::work() {
    while (!ended) {
        _gateway.tick();
    }
    return exit_status;
}
