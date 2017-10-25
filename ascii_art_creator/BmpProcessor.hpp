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

    void showImage() override {
        // declare and read the bitmap

        // convert each pixel to grayscale using RGB->YUV
        for (int j = 0; j < Input.TellHeight(); j++) {
            for (int i = 0; i < Input.TellWidth(); i++) {
                auto Temp = (int) floor(0.299 * Input(i, j)->Red +
                                       0.587 * Input(i, j)->Green +
                                       0.114 * Input(i, j)->Blue);
                if (Temp > 220) {
                    std::cout << " ";
                } else if (Temp > 190) {
                    std::cout << ".";
                } else if (Temp > 160) {
                    std::cout << "*";
                } else if (Temp > 130) {
                    std::cout << ":";
                } else if (Temp > 100) {
                    std::cout << "o";
                } else if (Temp > 70) {
                    std::cout << "&";
                } else if (Temp > 40) {
                    std::cout << "8";
                } else if (Temp > 10) {
                    std::cout << "#";
                } else {
                    std::cout << "@";
                }
            }
            std::cout << '\n';
        }
    }

protected:

    BMP Input;
};

#endif //CPP_MAGIC_ASCII_ART_CREATOR_TEAM_BMPPROCESSOR_HPP