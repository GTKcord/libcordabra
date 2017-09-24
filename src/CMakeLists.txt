cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(cordabra)

set(EXPORTS libcordabra discordclient.hpp token.hpp events/event.hpp)
set(PRIVATES )
set(SOURCES discordclient.cpp token.cpp)
add_library(cordabra SHARED ${EXPORTS} ${PRIVATES} ${SOURCES})

install(TARGETS cordabra 
        LIBRARY DESTINATION lib
)

install(FILES ${EXPORTS}
        DESTINATION include/libcordabra
)
