//
// Created by jeannie on 2017.10.24..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_TEAM_IMAGEPROCESSOR_H
#define CPP_MAGIC_ASCII_ART_CREATOR_TEAM_IMAGEPROCESSOR_H


#include <vector>

class ImageProcessor {

public:
    explicit ImageProcessor();
    virtual ~ImageProcessor();
    virtual void grayscale();
    virtual void showImage();
    void writeToFile();
    void convertToAscii();
    void resize(float);

protected:
    std::vector<std::vector<unsigned char>> grayscaleImage;

};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_TEAM_IMAGEPROCESSOR_H
