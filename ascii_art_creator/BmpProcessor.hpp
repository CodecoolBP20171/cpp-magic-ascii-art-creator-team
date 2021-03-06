//
// Created by jeannie on 2017.10.24..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_TEAM_BMPPROCESSOR_HPP
#define CPP_MAGIC_ASCII_ART_CREATOR_TEAM_BMPPROCESSOR_HPP

#include <iostream>
#include <cmath>
#include "ImageProcessor.h"
#include "EasyBMP.h"

class BmpProcessor : public ImageProcessor {

public:
    explicit BmpProcessor(std::string filename) {
        const char * filenameToOpen = filename.c_str();
        Input.ReadFromFile(filenameToOpen);
    }

    virtual ~BmpProcessor() {}

    void processImage(bool isAlreadyGrayscale) override {
        std::vector<unsigned char> rowOfPixels;
        for (int j = 0; j < Input.TellHeight(); j++) {
            rowOfPixels.clear();
            for (int i = 0; i < Input.TellWidth(); i++) {
                unsigned char pixel;
                if(isAlreadyGrayscale) {
                    pixel = (int)(Input(i, j)->Red);
                } else {
                    pixel = (int) floor(0.299 * Input(i, j)->Red +
                                        0.587 * Input(i, j)->Green +
                                        0.114 * Input(i, j)->Blue);
                }
                rowOfPixels.push_back(pixel);
            }
            grayscaleImage.push_back(rowOfPixels);
        }
    }

protected:

    BMP Input;
};

#endif //CPP_MAGIC_ASCII_ART_CREATOR_TEAM_BMPPROCESSOR_HPP