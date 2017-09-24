//! \file events/event.hpp
//! \brief INCLUDE libcordabra AND NOT THIS HEADER
#ifndef EVENT_HPP
#define EVENT_HPP

namespace events {
class Event;
}

#include "../discordclient.cpp"

namespace events {
class Event {
public:
    Event(Discord *client) : _client(client) {
    }
    Discord *client() {
        return _client;
    }

private:
    Discord *_client;
};
}

#endif /* EVENT_HPP */
