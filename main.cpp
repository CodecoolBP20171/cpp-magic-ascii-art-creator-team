#include <iostream>
#include <bits/unique_ptr.h>
#include "ascii_art_creator/BmpProcessor.hpp"
#include "ascii_art_creator/PngProcessor.hpp"
#include "ascii_art_creator/JpgProcessor.hpp"
#include "ArgumentsParser.h"


using namespace std;
int main( int argc, char* argv[] )
{
    Parser p(argc, argv);

    if(p.isValid()) {

        unique_ptr<ImageProcessor> image;

        if("bmp" == p.getFileType()) {
            image.reset (new BmpProcessor(p.getFileName()));
        } else if("png" == p.getFileType()) {
            image.reset (new PngProcessor(p.getFileName()));
        } else if("jpg" == p.getFileType()) {
            image.reset (new JpgProcessor(p.getFileName()));
        }

        image->processImage(!p.isColored());

        if(p.isOversized()) {
            image->resize(p.getResize());
        }

        image->convertToAscii();
        image->writeToFile("jpg_test2.txt");
        image->showImage();



    } else {
        if (!p.isValid()) {
            cout << "\nInvalid arguments. "
                    "Use: -f <filename>. "
                    "Options: -t<type=bmp|jpg|png>, -color, -r<value>.\n";
        }
    }

    return 0;
}
