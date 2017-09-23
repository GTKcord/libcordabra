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
    Discord bot(BotType::Client, "token");

    bot.on<MessageReceivedEvent>([] (auto event) { // auto (in this context) is available in C++14
        std::cout << event.message().rawText() << "\n";
    });

    return bot.work(); // Sets up an event loop which allows exiting from it with bot.exit(<<whatever value, default 0>>) (bot is passed with all objects and events
}
```
