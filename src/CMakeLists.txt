cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(cordabra)

set(EXPORTS libcordabra discordclient.hpp)
set(SOURCES discordclient.cpp)

add_library(cordabra SHARED ${EXPORTS} ${SOURCES})

install(TARGETS cordabra 
        LIBRARY DESTINATION lib
)

install(FILES ${EXPORTS}
        DESTINATION include/libcordabra
)
