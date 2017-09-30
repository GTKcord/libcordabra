#ifndef JSON_HPP
#define JSON_HPP

#include "../decoder.hpp"

class JsonDecoder : public Decoder {
public:
    void decode() override;
};

#endif /* JSON_HPP */
