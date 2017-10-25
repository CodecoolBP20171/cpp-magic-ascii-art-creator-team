#include <iostream>
#include <bits/unique_ptr.h>
#include "ascii_art_creator/BmpProcessor.hpp"
#include "ascii_art_creator/PngProcessor.hpp"


using namespace std;
int main( int argc, char* argv[] )
{
    //std::unique_ptr<ImageProcessor> a (new BmpProcessor(argc, argv));
    //a->showImage();

    std::unique_ptr<ImageProcessor> b (new PngProcessor(argc, argv));
    b->showImage();
    return 0;
}
