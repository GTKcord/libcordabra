//! \file discordclient.hpp
//! \brief INCLUDE libcordabra AND NOT THIS HEADER
#ifndef DISCORDCLIENT_HPP
#define DISCORDCLIENT_HPP

class Discord;

#include "events/event.hpp"
#include <functional>
#include <map>
#include <vector>

using events::Event;

enum class AccountType { Bot, Client };

/// Main class for control
/**
 * Provides an interface to ID-based getters and the event handler, and general bot control.
 */
class Discord {
public:
    /// Constructs a client with type for token
    Discord(AccountType type, std::string token);
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
    void on(std::function<void(T)> handler, std::function<bool(T)> filter = [](T) { return true; }) {
        auto events = get_vector<T>();
        events.push_back(std::make_pair(handler, filter));
    }

private:
    // C++ static magic allows to map T to a Discord object and a vector like this.
    template <typename T> std::vector<std::function<void(T)>, std::function<void(T)>> &get_vector() {
        static_assert(std::is_base_of<Event, T>::value, "Passed T must inherit Event");
        static std::map<Discord *, std::vector<std::pair<std::function<void(T)>, std::function<void(T)>>>> events;
        auto iter = events.find(this);
        if (iter == events.end()) {
            iter = events.insert(std::make_pair(this, std::vector<std::function<void(T)>, std::function<void(T)>>())).first;
            delete_calls.push_back([this]() { events.erase(this); });
        }
        return iter->second;
    }
    std::vector<std::function<void()>> delete_calls;
};

#endif /* DISCORDCLIENT_HPP */
