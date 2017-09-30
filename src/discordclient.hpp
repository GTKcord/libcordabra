//! \file discordclient.hpp
//! \brief INCLUDE libcordabra AND NOT THIS HEADER
#ifndef DISCORDCLIENT_HPP
#define DISCORDCLIENT_HPP

#include "endpoints.hpp"
#include "events/event.hpp"
#include "gateway/gateway.hpp"
#include "token.hpp"
#include <functional>
#include <map>
#include <vector>

/// Main class for control
/**
 * Provides an interface to ID-based getters and the event handler, and general bot control.
 */
class Discord {
public:
    /// Constructs a client with type for token
    explicit Discord(Token token, GatewayType type, std::string apiPrefix);
    ~Discord() {
        for (const std::function<void()> &f : delete_calls) {
            f();
        }
        delete_calls.clear();
    }

    /// Inserts an event handler for event T with a handler and optionally filter
    /**
     * The event handlers are mapped on a per client+event basis.
     * The calls will be made every time the event T is invoked if and only if filter confirms the action
     */
    template <typename T>
    void on(std::function<void(const T &)> handler, std::function<bool(const T &)> filter = [](T) { return true; }) {
        auto events = get_vector<T>();
        events.push_back(std::make_pair(handler, filter));
    }

    /// Sets up and logs in the bot
    /*
     * Sets up the event loop and logs the bot into Discord, retrieves all guilds, and fires ReadyEvent.
     */
    int work();

private:
    // gateway
    GatewayType _type;
    Gateway _gateway;
    Endpoints _endpoints;

    // C++ static magic allows to map T to a Discord object and a vector like this.
    template <typename T> std::vector<std::function<void(const T &)>, std::function<void(const T &)>> &get_vector() {
        using events::Event;
        static_assert(std::is_base_of<Event, T>::value, "Passed T must inherit Event");
        static std::map<Discord *, std::vector<std::pair<std::function<void(const T &)>, std::function<void(const T &)>>>> events;
        auto iter = events.find(this);
        if (iter == events.end()) {
            iter = events
                   .insert(std::make_pair(this, std::vector<std::function<void(const T &)>, std::function<void(const T &)>>()))
                   .first;
            delete_calls.push_back([this]() { events.erase(this); });
        }
        return iter->second;
    }
    std::vector<std::function<void()>> delete_calls;

    Token _token;
    // exit() handlers
    bool ended = false;
    int exit_status = 0;
};

#endif /* DISCORDCLIENT_HPP */
