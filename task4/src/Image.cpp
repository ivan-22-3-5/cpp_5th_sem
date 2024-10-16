#include "Image.h"

#include <fstream>
#include <iostream>


Image::Image(const unsigned int width, const unsigned int height)
    : width(width), height(height), pixels(width * height, 0) {
}

Image::Image(const unsigned int width, const unsigned int height, const unsigned char filling_value)
    : width(width), height(height), pixels(width * height, filling_value) {
}

unsigned int Image::get_width() const {
    return width;
}

unsigned int Image::get_height() const {
    return height;
}

unsigned int Image::get_pixel(const unsigned int x, const unsigned int y) const {
    return pixels.at(y * width + x);
}

void Image::set_pixel(const unsigned int x, const unsigned int y, const unsigned char value) {
    pixels.at(y * width + x) = value;
}

void Image::save_as_file(const std::string& filename) const {
    std::ofstream file(filename + ".pgm", std::ios::binary);
    if (!file) {
        std::cerr << "Error: File could not be opened." << std::endl;
    }
    file << "P5\n" << width << " " << height << "\n" << "255\n";
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            file << pixels.at(y * width + x);
        }
        file << "\n";
    }
    file.close();
}

std::vector<unsigned int> Image::build_histogram(unsigned char colnum) const {
    int step = 255/colnum;
    std::vector<unsigned int> histogram(colnum, 0);
    for (auto pixel:pixels) {
        histogram[pixel/step]++;
    }
    return histogram;
}
