//
// Created by apha on 2017.10.25..
//

#include "ImageProcessor.h"
#include <iostream>
#include "lodepng.h"

class PngProcessor: public ImageProcessor {

public:
    explicit PngProcessor(int argc, char* argv[]) {
        //decode
        std::string filename = argv[1];
        unsigned error = lodepng::decode(image, width, height, filename);

        //if there's an error, display it
        if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

        //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
    };
    virtual ~PngProcessor() {};

    void grayscale(){
        char grayscaleImage[height][width];
        int pngIndex = 0;
        for(int y = 0; y < height; y++) {
            for(int x = 0; x < width; x++) {
                grayscaleImage[y][x] = floor((0.3 * image[pngIndex]) + (0.59 * image[pngIndex+1]) + (0.11 * image[pngIndex+2]));
                pngIndex += 4;
            }
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width ; ++j) {
                std::cout << static_cast<int>(grayscaleImage[height][width]) << " ";
            }
            std::cout << "\n";
        }
    };

    virtual void showImage(){
        //TODO print the loaded pixels
        grayscale();
        //int i=0;
        //for(auto& pixel: image) {
        //    if(i % 40 == 0) {
        //        std::cout << std::endl;
        //    }
        //    std::cout << static_cast<int>(pixel) << " ";
        //    i++;
        //}
        //std::cout << "width: " << width << "\n";
        //std::cout << "height: " << height << "\n";
    };
private:
    std::vector<unsigned char> image;
    unsigned width;
    unsigned height;
};