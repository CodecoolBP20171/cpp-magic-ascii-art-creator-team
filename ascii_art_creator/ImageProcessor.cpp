//
// Created by jeannie on 2017.10.24..
//

#include <iostream>
#include <fstream>
#include "ImageProcessor.h"

ImageProcessor::ImageProcessor() {
}

ImageProcessor::~ImageProcessor() {}

void ImageProcessor::showImage() {

    for (int i = 0; i < grayscaleImage.size(); ++i) {
        for (int j = 0; j < grayscaleImage[i].size(); ++j) {
            std::cout << grayscaleImage[i][j];
        }
        std::cout << std::endl;
    }
}

void ImageProcessor::writeToFile() {
    std::ofstream filename;
    filename.open("ascii.txt");
    for (int i = 0; i < grayscaleImage.size(); ++i) {
        for (int j = 0; j < grayscaleImage[i].size(); ++j) {
            filename << grayscaleImage[i][j];
        }
        filename << std::endl;
    }
    filename.close();
}

void ImageProcessor::convertToAscii() {

    for (int i = 0; i < grayscaleImage.size(); ++i) {
        for (int j = 0; j < grayscaleImage[i].size(); ++j) {
            if (grayscaleImage[i][j] > 220) {
                grayscaleImage[i][j] = ' ';
            } else if (grayscaleImage[i][j]> 190) {
                grayscaleImage[i][j] = '.';
            } else if (grayscaleImage[i][j]> 160) {
                grayscaleImage[i][j] = '*';
            } else if (grayscaleImage[i][j]> 130) {
                grayscaleImage[i][j] = ':';
            } else if (grayscaleImage[i][j]> 100) {
                grayscaleImage[i][j] = 'o';
            } else if (grayscaleImage[i][j]> 70) {
                grayscaleImage[i][j] = '&';
            } else if (grayscaleImage[i][j]> 40) {
                grayscaleImage[i][j] = '8';
            } else if (grayscaleImage[i][j]> 10) {
                grayscaleImage[i][j] = '#';
            } else {
                grayscaleImage[i][j] = '@';
            }
        }
    }
}

void ImageProcessor::grayscale() {}
