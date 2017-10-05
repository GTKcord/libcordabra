#include "token.hpp"

namespace libcordabra {
    Token::Token(std::string token, Type type) : _type(type) {
        switch (type) {
        case Client:
            _token = token;
            break;
        case Bot:
            _token = "Bot " + token;
            break;
        case Bearer:
            _token = "Bearer " + token;
        }
    }

    std::string Token::token() {
        int pos = _token.find(' ');
        return pos != std::string::npos ? _token.substr(pos) : _token;
    }
}
