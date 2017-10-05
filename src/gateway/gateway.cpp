#include "gateway.hpp"
#include "decoder/json.hpp"

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
            // TODO init client and send identify
            break;
        }
    }
}
