#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <string>
#include <vector>

#include "../Pixel.h"

class ImageLoader {
public:
    virtual ~ImageLoader() = default;
    virtual void load(std::vector<Pixel>& pixels, unsigned int &width, unsigned int &height, const std::string &filename) = 0;
    virtual void save_as_file(const std::vector<Pixel> &pixels, unsigned int width, unsigned int height, const std::string &filename) = 0;
};

#endif