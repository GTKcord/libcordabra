#include "gateway.hpp"
#include "../discordclient.hpp"
#include "../endpoints.hpp"
#include "decoder/json.hpp"

#include "../rest/rest.hpp"

namespace libcordabra {
    Gateway::Gateway(Discord *client, GatewayType type) : _client(client) {
        switch (type) {
        case GatewayType::JSON:
            _decoder = new JsonDecoder();
            break;
        }
    }

    void Gateway::tick() {
        using namespace rest;
        switch (_state) {
        case GatewayStart:
            request<GET>((_client->_endpoints.get_endpoint(Endpoint::Gateway)),
                         [this](Response response) { this->gateway_url = decode_string(response.get_buffer()); });
            break;
        }
    }
}
