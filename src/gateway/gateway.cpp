#include "gateway.hpp"
#include "decoder/json.hpp"
#include "../endpoints.hpp"
#include "../discordclient.hpp"

namespace libcordabra {
    Gateway::Gateway(Discord *client, GatewayType type) : _client(client) {
        switch (type) {
        case GatewayType::JSON:
            _decoder = new JsonDecoder();
            break;
        }
    }

    void Gateway::tick() {
            switch (_state) {
            case GatewayStart:
            gateway_url = rest::get::string(_client->_endpoints.getEndpoint(Endpoint::Gateway));
            break;
        }
    }
}
