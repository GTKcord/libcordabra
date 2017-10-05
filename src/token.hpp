#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

namespace libcordabra {
    class Token {
    public:
        enum Type { Client, Bot, Bearer };
        Token(std::string token, Type type = Client);
        std::string full_token() {
            return _token;
        }
        std::string token();
        Type type() {
            return _type;
        }

    private:
        Type _type;
        std::string _token;
    };
}
#endif /* TOKEN_HPP */
