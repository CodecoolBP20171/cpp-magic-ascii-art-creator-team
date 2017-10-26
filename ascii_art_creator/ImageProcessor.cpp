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

void ImageProcessor::resize(float percentage) {
    std::vector<std::vector<unsigned char>> tempImage;

    // get the size of the chunk to resize to
    size_t chunkSize = grayscaleImage[0].size() / (grayscaleImage[0].size() * percentage);
    size_t tempWidth = grayscaleImage[0].size() / chunkSize;
    size_t tempHeight = grayscaleImage.size() / chunkSize;

    for (int y = 0; y < tempHeight ; ++y) {
        std::vector<unsigned char> rowOfPixels;
        unsigned int averagedPixel;
        for (int x = 0; x < tempWidth; ++x) {
            averagedPixel = 0;
            for (int i = 0; i < chunkSize; ++i) {
                for (int j = 0; j < chunkSize; ++j) {
                    averagedPixel += grayscaleImage[y*chunkSize+i][x*chunkSize+j];
                }
            }
            averagedPixel = averagedPixel / (chunkSize * chunkSize);
            rowOfPixels.push_back(static_cast<unsigned char>(averagedPixel));
        }
        tempImage.push_back(rowOfPixels);
    }
    grayscaleImage = tempImage;
}
