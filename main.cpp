#include <iostream>
#include <bits/unique_ptr.h>
#include "ascii_art_creator/BmpProcessor.hpp"
#include "ascii_art_creator/PngProcessor.hpp"
#include "ascii_art_creator/JpgProcessor.hpp"


using namespace std;
int main( int argc, char* argv[] )
{
    //std::unique_ptr<ImageProcessor> a (new BmpProcessor(argc, argv));
    //a->grayscale();
    //a->convertToAscii();
    //a->writeToFile();
    //a->showImage();

    //std::unique_ptr<ImageProcessor> b (new PngProcessor(argc, argv));
    //b->grayscale();
    //b->convertToAscii();
    //b->writeToFile();
    //b->showImage();

    std::unique_ptr<ImageProcessor> c (new JpgProcessor(argc, argv));
    //c->grayscale();
    //c->convertToAscii();
    //c->writeToFile();
    //c->showImage();
    return 0;
}
