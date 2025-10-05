cmake_minimum_required(VERSION 3.10)
project(sfml_app)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "/opt/homebrew/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(sfml_app main.cpp
        Class/Player/Player.cpp
        Class/Player/Player.h
        Class/Map/Map.cpp
        Class/Map/Map.h)

target_link_libraries(sfml_app SFML::Graphics SFML::Window SFML::System)
