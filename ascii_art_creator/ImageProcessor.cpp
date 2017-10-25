//
// Created by jeannie on 2017.10.24..
//

#include <iostream>
#include "ImageProcessor.h"

ImageProcessor::ImageProcessor() {
}

ImageProcessor::~ImageProcessor() {}

void ImageProcessor::processImage() {
    std::cout << "BmpProcessor" << std::endl;
}

void ImageProcessor::showASCIIart() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            if (picture[index] > 220) {
                std::cout << " ";
            } else if (picture[index] > 190) {
                std::cout << ".";
            } else if (picture[index] > 160) {
                std::cout << "*";
            } else if (picture[index] > 130) {
                std::cout << ":";
            } else if (picture[index] > 100) {
                std::cout << "o";
            } else if (picture[index] > 70) {
                std::cout << "&";
            } else if (picture[index] > 40) {
                std::cout << "8";
            } else if (picture[index] > 10) {
                std::cout << "#";
            } else {
                std::cout << "@";
            }
        }
        std::cout << '\n';
    }
}
