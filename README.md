# libdiscordpp
C++ library for the Discord API wrapper  
**CURRENTLY PRERELEASE AND NOT DONE AT ALL**

## Example code
```cpp
#include <libdiscordpp/libdiscordpp>
// Includes all required headers for work
#include <iostream>

using libdiscordpp::BotType;
using libdiscordpp::Events::MessageReceivedEvent;
using libdiscordpp::Discord;

int main() {
    Discord bot(AccountType::Client, "token");

    // on<T>(std::function<void(const T&)>)
    // on<event>(handler)
    bot.on<GuildJoinedEvent>([] (auto event) { // auto (in this context) is available in C++14
        std::cout << event.guild() << "\n";
    });

    // on<T>(std::function<void(const T&)>, std::function<bool(const T&)>)
    // on<event>(handler, filter)
    bot.on<MessageReceivedEvent>([] (auto event) {
        event.channel().stream() << "Hi there" << event.author(); // stream().no_space() etc.
    }, [] (auto event) {
        return event.message().rawText() == "Hi Bot!";
    });

    return bot.work(); // Sets up an event loop which allows exiting from it with bot.exit(<<whatever value, default 0>>) (bot is passed with all objects and events
}
```
