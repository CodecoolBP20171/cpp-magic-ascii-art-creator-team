//
// Created by jeannie on 2017.10.24..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_TEAM_IMAGEPROCESSOR_H
#define CPP_MAGIC_ASCII_ART_CREATOR_TEAM_IMAGEPROCESSOR_H


class ImageProcessor {

public:
    ImageProcessor();
    virtual ~ImageProcessor();

protected:
    virtual void readFile();
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_TEAM_IMAGEPROCESSOR_H
