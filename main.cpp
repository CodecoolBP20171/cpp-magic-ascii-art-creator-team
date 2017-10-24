#include <iostream>
#include <bits/unique_ptr.h>
#include "ascii_art_creator/BmpProcessor.hpp"


using namespace std;
int main( int argc, char* argv[] )
{
    std::unique_ptr<ImageProcessor> a (new BmpProcessor(argc, argv));
    a->showImage();

    return 0;
}
