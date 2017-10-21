#ifndef GATEWAY_HPP
#define GATEWAY_HPP

#include "decoder.hpp"
#include <string>

namespace libcordabra {
    class Discord;
    enum class GatewayType { JSON };
    class Gateway {
        friend class JsonDecoder;

    public:
        explicit Gateway(Discord *client, GatewayType type);
        void tick();
        ~Gateway();

    private:
        enum State { GatewayStart };

        std::string gateway_url;
        Decoder *_decoder;
        Discord *_client;
        State _state;
    };
}
#endif /* GATEWAY_HPP */
