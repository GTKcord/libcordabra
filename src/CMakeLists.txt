cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(cordabra)


set(EXPORTS libcordabra discordclient.hpp token.hpp gateway/gateway.hpp events/event.hpp gateway/decoder.hpp gateway/decoder/json.hpp)
set(SOURCES discordclient.cpp token.cpp gateway/gateway.cpp gateway/decoder/json.cpp)
add_library(cordabra SHARED ${EXPORTS} ${SOURCES})

add_subdirectory(external/)

install(TARGETS cordabra 
        LIBRARY DESTINATION lib
)

install(FILES ${EXPORTS}
        DESTINATION include/libcordabra
)
