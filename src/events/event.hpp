//! \file events/event.hpp
//! \brief INCLUDE libcordabra AND NOT THIS HEADER
#ifndef EVENT_HPP
#define EVENT_HPP

class Discord;

namespace events {
class Event {
    friend class Discord;
public:
    Discord *client() {
        return _client;
    }

private:
    void setClient(Discord *client) {
        _client = client;
    }
    Discord *_client;
};
}

#endif /* EVENT_HPP */
