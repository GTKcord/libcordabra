#include "endpoints.hpp"

#include <exception>

namespace libcordabra {
    std::string Endpoints::get_endpoint(Endpoint endpoint, std::initializer_list<std::string> args) {
        std::string rawpoint = endpointMap[endpoint];
        std::string ret = "";
        auto j = args.begin();
        for (int i = 0; i < rawpoint.size(); i++) {
            if (i + 1 != rawpoint.size() && rawpoint[i] == '{' && rawpoint[i + 1] == '}') {
                i++;
                if (args.end() == ++j) throw std::runtime_error("Too little arguments for endpoint");
                ret += *j;
            } else
                ret += rawpoint[i];
        }

        return prefix + ret;
    }
}
