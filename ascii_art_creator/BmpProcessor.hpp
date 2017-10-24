//
// Created by jeannie on 2017.10.24..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_TEAM_BMPPROCESSOR_HPP
#define CPP_MAGIC_ASCII_ART_CREATOR_TEAM_BMPPROCESSOR_HPP

#include <iostream>
#include "ImageProcessor.h"

class BmpProcessor : public ImageProcessor {

public:
    BmpProcessor() {}
    virtual ~BmpProcessor() {}

protected:
    void readFile() override {
        std::cout << "BmpProcessor" << std::endl;
    }
};

#endif //CPP_MAGIC_ASCII_ART_CREATOR_TEAM_BMPPROCESSOR_HPP