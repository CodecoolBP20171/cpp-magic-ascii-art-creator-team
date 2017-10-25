//
// Created by apha on 2017.10.25..
//

#include "ImageProcessor.h"
#include <iostream>
#include "lodepng.h"

class PngProcessor: public ImageProcessor {

public:
    explicit PngProcessor(int argc, char* argv[]) {
        std::string filename = argv[1];
        unsigned error = lodepng::decode(image, width, height, filename);
        if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    };

    virtual ~PngProcessor() {};

    void grayscale() override {
        int pngIndex = 0;
        std::vector<unsigned char> rowOfPixels;
        for(int y = 0; y < height; y++) {
            rowOfPixels.clear();
            for(int x = 0; x < width; x++) {
                rowOfPixels.push_back((0.3 * image[pngIndex]) + (0.59 * image[pngIndex+1]) + (0.11 * image[pngIndex+2]));
                pngIndex += 4;
            }
            grayscaleImage.push_back(rowOfPixels);

        }
    };

private:
    std::vector<unsigned char> image;
    unsigned width;
    unsigned height;
};