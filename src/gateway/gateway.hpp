#ifndef GATEWAY_HPP
#define GATEWAY_HPP

class Gateway;
#include "decoder/json.hpp"

class Gateway {
    friend class JsonDecoder;

public:
    /// The decoder type to use (JSON, and soon ETF)
    enum Type { JSON };
    explicit Gateway(Type type);
    ~Gateway();

private:
    Decoder *_decoder;
};

#endif /* GATEWAY_HPP */
