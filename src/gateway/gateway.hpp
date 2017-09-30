#ifndef GATEWAY_HPP
#define GATEWAY_HPP

#include "decoder.hpp"

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

    Decoder *_decoder;
    Discord *_client;
    State _state;
};

#endif /* GATEWAY_HPP */
