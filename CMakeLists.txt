cmake_minimum_required(VERSION 3.25)

project(ClassicCreatorLayer)

set(CMAKE_CXX_STANDARD 20)

find_package(Geode REQUIRED)

add_geode_mod(
    ${PROJECT_NAME}
    WIN32
    ANDROID
    
    SOURCES
        main.cpp
)

