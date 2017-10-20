#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

namespace libcordabra {
    /// Token for bot/user login/oauth login
    class Token {
    public:
        enum Type { Client, Bot, Bearer };
        Token(std::string token, Type type = Client);
        /// Returns the entire token
        std::string full_token() {
            return _token;
        }
        /// Returns token stripped of it's type
        std::string token();
        /// Returns token type
        Type type() {
            return _type;
        }

    private:
        Type _type;
        std::string _token;
    };
}
#endif /* TOKEN_HPP */
