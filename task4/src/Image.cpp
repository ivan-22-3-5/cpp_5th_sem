#include "Image.h"


Image::Image(const unsigned int width, const unsigned int height)
    : width(width), height(height), data(width * height, 0) {
}

Image::Image(const unsigned int width, const unsigned int height, const unsigned char filling_value)
    : width(width), height(height), data(width * height, filling_value) {
}

unsigned int Image::get_width() const {
    return width;
}

unsigned int Image::get_height() const {
    return height;
}

unsigned int Image::get_pixel(const unsigned int x, const unsigned int y) const {
    return data.at(y * width + x);
}

void Image::set_pixel(const unsigned int x, const unsigned int y, const unsigned char value) {
    data.at(y * width + x) = value;
}
