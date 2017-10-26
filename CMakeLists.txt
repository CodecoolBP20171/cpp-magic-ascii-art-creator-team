cmake_minimum_required(VERSION 3.8)
project(cpp_magic_ascii_art_creator_team)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ascii_art_creator/PngProcessor.hpp
        ascii_art_creator/BmpProcessor.hpp
        ascii_art_creator/JpgProcessor.hpp
        ascii_art_creator/ImageProcessor.cpp
        ascii_art_creator/ImageProcessor.h
        easybmp/EasyBMP.cpp
        easybmp/EasyBMP.h
        easybmp/EasyBMP_BMP.h
        easybmp/EasyBMP_DataStructures.h
        easybmp/EasyBMP_VariousBMPutilities.h
<<<<<<< HEAD
        lodepng/lodepng.h
        lodepng/lodepng.cpp
        nanojpeg/nanojpeg.c
        main.cpp)
=======
        main.cpp ArgumentsParser.cpp ArgumentsParser.h)
>>>>>>> parsing

add_executable(cpp_magic_ascii_art_creator_team ${SOURCE_FILES})
include_directories(easybmp lodepng nanojpeg)