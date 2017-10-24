//
// Created by jeannie on 2017.10.24..
//

#include <iostream>
#include "ImageProcessor.h"

ImageProcessor::ImageProcessor() {
    readFile();
}

ImageProcessor::~ImageProcessor() {}

void ImageProcessor::readFile() {
    std::cout << "BmpProcessor" << std::endl;
}
