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
    explicit BmpProcessor(int argc, char* argv[]) {
        Input.ReadFromFile(argv[1]);
    }

    virtual ~BmpProcessor() {}

    void grayscale() override {
        std::vector<unsigned char> rowOfPixels;
        for (int j = 0; j < Input.TellHeight(); j++) {
            rowOfPixels.clear();
            for (int i = 0; i < Input.TellWidth(); i++) {
                unsigned char pixel = (int) floor(0.299 * Input(i, j)->Red +
                                       0.587 * Input(i, j)->Green +
                                       0.114 * Input(i, j)->Blue);
                rowOfPixels.push_back(pixel);
            }
            grayscaleImage.push_back(rowOfPixels);
        }
    }

protected:

    BMP Input;
};

#endif //CPP_MAGIC_ASCII_ART_CREATOR_TEAM_BMPPROCESSOR_HPP