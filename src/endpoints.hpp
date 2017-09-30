#ifndef ENDPOINTS_HPP
#define ENDPOINTS_HPP

#include <initializer_list>
#include <map>
#include <string>

/// Endpoint names to use in getEndpoint
enum class Endpoint {
    /// Gateway URL endpoint
    Gateway
};

/// This class compiles and makes endpoints.
// And exists as a class only so endpoints can be changed
class Endpoints {
public:
    explicit Endpoints(std::string prefix) : prefix(prefix) {
    }
    /// Looks up and compiles an endpoint URL string
    std::string getEndpoint(Endpoint endpoint, std::initializer_list<std::string> args = {});

private:
    std::string prefix = "https://discordapp.com/api/";
    std::map<Endpoint, std::string> endpointMap{ { Endpoint::Gateway, "gateway/" } };
};
#endif /* ENDPOINTS_HPP */
