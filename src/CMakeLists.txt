cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(libdiscordpp)

set(EXPORTS libdiscordpp discordclient.hpp)
set(SOURCES discordclient.cpp)

add_library(libdiscordpp SHARED ${EXPORTS} ${SOURCES})

install(TARGETS libdiscordpp 
        LIBRARY DESTINATION lib
)

install(FILES ${EXPORTS}
        DESTINATION include/libdiscordpp
)
