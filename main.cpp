#include <iostream>
#include <bits/unique_ptr.h>
#include "ascii_art_creator/BmpProcessor.hpp"
#include "ascii_art_creator/PngProcessor.hpp"
#include "ascii_art_creator/JpgProcessor.hpp"


using namespace std;
int main( int argc, char* argv[] )
{
    //std::unique_ptr<ImageProcessor> a (new BmpProcessor(argc, argv));
    //a->processImage(true);
    //a->resize(0.2f);
    //a->convertToAscii();
    //a->writeToFile("bmpToAscii.txt");
    //a->showImage();

    std::unique_ptr<ImageProcessor> b (new PngProcessor(argc, argv));
    b->processImage(false);
    b->resize(0.8f);
    b->convertToAscii();
    b->writeToFile("pngToAscii.txt");
    b->showImage();

    //std::unique_ptr<ImageProcessor> c (new JpgProcessor(argc, argv));
    //c->processImage(false);
    //c->resize(0.2f);
    //c->convertToAscii();
    //c->writeToFile("jpgToAscii.txt");
    //c->showImage();
    return 0;
}
