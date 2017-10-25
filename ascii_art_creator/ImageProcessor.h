//
// Created by jeannie on 2017.10.24..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_TEAM_IMAGEPROCESSOR_H
#define CPP_MAGIC_ASCII_ART_CREATOR_TEAM_IMAGEPROCESSOR_H

#include <iostream>
#include <vector>

class ImageProcessor {

public:
    explicit ImageProcessor();
    virtual ~ImageProcessor();
    virtual void processImage();
    void showASCIIart();

protected:
    unsigned width;
    unsigned height;
    std::vector<unsigned> picture;
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_TEAM_IMAGEPROCESSOR_H
