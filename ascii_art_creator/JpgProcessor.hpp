//
// Created by András on 2017. 10. 25..
//
#include "../nanojpeg/nanojpeg.c"
#include "ImageProcessor.h"
#include <iostream>
#include <fstream>
#include <sstream>

class JpgProcessor: public ImageProcessor {

public:
    explicit JpgProcessor(int argc, char* argv[]) {
        FILE * pfile;
        long lsize;
        char * buffer;
        size_t result;

        pfile = fopen(argv[1], "rb");
        if(nullptr == pfile) {fputs("File error", stderr); exit(1);}

        // obtain file size
        fseek(pfile, 0, SEEK_END);
        lsize = ftell(pfile);
        rewind(pfile);

        // allocate memory to contain the whole file
        buffer = (char *) malloc(sizeof(char)*lsize);

        //copy the file into the buffer
        result = fread(buffer,1, lsize, pfile);
        fread(buffer,1, lsize, pfile);

        njInit();
        nj_result_t error;
        error = njDecode(buffer, lsize);
        unsigned char *imagePtr;
        if(!error) {
            imagePtr = njGetImage();
            width = njGetWidth();
            height = njGetHeight();
        }
        for (int i = 0; i < njGetImageSize() ; ++i) {
            image.push_back(*(imagePtr+i));
        }
        njDone();
    };

    virtual ~JpgProcessor() {};

    void processImage(bool isAlreadyGreyscale) override {
        int pngIndex = 0;
        std::vector<unsigned char> rowOfPixels;
        for(int y = 0; y < height; y++) {
            rowOfPixels.clear();
            for(int x = 0; x < width; x++) {
                if(isAlreadyGreyscale){
                    rowOfPixels.push_back(image[pngIndex]);
                } else {
                    rowOfPixels.push_back(floor((0.3 * image[pngIndex] + (0.59 * image[pngIndex+1]) + (0.11 * image[pngIndex+2]))));
                }
                pngIndex += 3;
            }
            grayscaleImage.push_back(rowOfPixels);
        }
    };

private:
    std::vector<unsigned char> image;
    int width;
    int height;
};
