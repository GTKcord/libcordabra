#ifndef JSON_HPP
#define JSON_HPP

class JsonDecoder;
#include "../decoder.hpp"
#include "../gateway.hpp"

class JsonDecoder : public Decoder {
public:
    JsonDecoder(Gateway* gateway) : _gateway(gateway) {
    }
    void decode() override;

private:
    Gateway *_gateway;
};

#endif /* JSON_HPP */
