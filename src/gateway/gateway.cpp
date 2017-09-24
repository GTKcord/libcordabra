#include "gateway.hpp"
#include "decoder/json.hpp"

Gateway::Gateway(Type type) {
    switch (type) {
        case JSON:
            _decoder = new JsonDecoder(this);
            break;
    }
}
