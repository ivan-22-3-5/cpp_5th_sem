#include "Image.h"


Image::Image(const unsigned int width, const unsigned int height)
    : width(width), height(height), data(width * height, 255) {
}

unsigned int Image::get_width() const {
    return width;
}

unsigned int Image::get_height() const {
    return height;
}