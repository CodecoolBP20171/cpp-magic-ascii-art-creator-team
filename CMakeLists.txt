cmake_minimum_required(VERSION 3.8)
project(cpp_magic_ascii_art_creator_team)

set(CMAKE_CXX_STANDARD 11)

set(HEADER_FILES ascii_art_creator/ImageProcessor.h ascii_art_creator/BmpProcessor.hpp)

set(SOURCE_FILES
        main.cpp
        ascii_art_creator/ImageProcessor.cpp)

add_executable(cpp_magic_ascii_art_creator_team ${SOURCE_FILES} ${HEADER_FILES})