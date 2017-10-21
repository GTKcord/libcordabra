#ifndef REST_HPP
#define REST_HPP

#include <boost/beast.hpp>
#include <functional>
#include <map>
#include <string>

namespace libcordabra {
    namespace rest {
        /// Response from the server
        class Response {
        public:
            /// Returns the response data buffer
            boost::beast::flat_buffer get_buffer();

        private:
            boost::beast::flat_buffer buffer;
        };

        /// HTTP method
        enum Method { GET, POST, PUT, DELELE, PATCH };

        /// Convers a buffer into a string
        std::string decode_string(boost::beast::flat_buffer buffer);

        /// Makes a REST request with method specified onto url with a callback and optional headers.
        template <Method m>
        void request(std::string url,
                     std::function<void(Response)> response = []() {},
                     std::map<std::string, std::string> headers = {}) { // TODO
        }

        namespace __private {
            void send_request(std::string url, Method m, std::function<void(Response)>());
        }
    }
}
#endif /* REST_HPP */
