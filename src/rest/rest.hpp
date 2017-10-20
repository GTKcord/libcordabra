#ifndef REST_HPP
#define REST_HPP

#include <functional>

namespace libcordabra {
    namespace rest {

        class Response {
            char *get_response_data();
            long get_length();
        };

        enum Method {
            GET,
            POST,
            PUT,
            DELELE,
            PATCH
        }

        template <Method m>
        void request() { // TODO
        }

        namespace __private {
            void sendRequest(std::string url, Method m, char *bytes, long length, std::function<void(Response)>());
        }
    }
}
#endif /* REST_HPP */
