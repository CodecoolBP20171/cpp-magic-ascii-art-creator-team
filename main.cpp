#include <iostream>
<<<<<<< HEAD
#include <bits/unique_ptr.h>
#include "ascii_art_creator/BmpProcessor.hpp"
#include "ascii_art_creator/PngProcessor.hpp"
#include "ascii_art_creator/JpgProcessor.hpp"
=======
#include "ArgumentsParser.h"
>>>>>>> parsing


using namespace std;
int main( int argc, char* argv[] )
{
<<<<<<< HEAD
    //std::unique_ptr<ImageProcessor> a (new BmpProcessor(argc, argv));
    //a->processImage(true);
    //a->resize(0.2f);
    //a->convertToAscii();
    //a->writeToFile("bmpToAscii.txt");
    //a->showImage();
=======


    char *fsw = "-f";
    char *fname = "test.bmp";
    char *tsw = "-t";
    char *ft = "bmp";
    char *colsw = "-color";
    char *sizesw = "-r";
    char *size = "0.5";

    char* arr[] = {fname, fsw, fname, sizesw, size};

    Parser p(5, arr);

    std::cout << "Valid: " << p.isValid();
    std::cout << ", filename: " << p.getFileName();
    std::cout << ", filetype: " << p.getFileType();
    std::cout << ", color: " << p.isColored();
    std::cout << ", resize: " << p.isOversized();
    std::cout << ", value: " << p.getResize();


    /*if (!p.isValid()) {
        cout << "\nInvalid arguments. "
                "Use: -f <filename>. "
                "Options: -t<type=bmp|jpg|png>, -color, -r<value>.\n";
        return 0;
    }*/
>>>>>>> parsing

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
