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
    Discord *client();
};
}

#endif /* EVENT_HPP */
