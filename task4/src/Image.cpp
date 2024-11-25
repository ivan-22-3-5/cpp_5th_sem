#include "Image.h"

#include <fstream>
#include <iostream>


Image::Image(const unsigned int width, const unsigned int height)
    : width(width), height(height), pixels(width * height, 0) {
}

Image::Image(const unsigned int width, const unsigned int height, const unsigned char filling_value)
    : width(width), height(height), pixels(width * height, filling_value) {
}

void Image::read_pixels(std::ifstream& file) {
    file >> width >> height;
    pixels.resize(width * height);
    file.ignore(4);
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            file >> pixels.at(y * width + x);
        }
    }
}

void Image::skip_comments(std::ifstream& file) {
    char ch;
    file >> ch;
    while (ch == '#') {
        std::string comment_line;
        std::getline(file, comment_line);
        file >> ch;
    }
    file.unget();
}

Image::Image(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: File could not be opened." << std::endl;
        return;
    }

    std::string magic_number;
    file >> magic_number;
    if (magic_number != "P5") {
        std::cerr << "Error: Unsupported file format." << std::endl;
        return;
    }

    skip_comments(file);
    read_pixels(file);

    file.close();
}
unsigned int Image::get_width() const {
    return width;
}

unsigned int Image::get_height() const {
    return height;
}

unsigned int Image::get_pixel(const unsigned int x, const unsigned int y) const {
    if (x >= width || y >= height) {
        throw std::out_of_range("Index out of bounds.");
    }
    return pixels.at(y * width + x);
}

void Image::set_pixel(const unsigned int x, const unsigned int y, const unsigned char value) {
    if (x >= width || y >= height) {
        throw std::out_of_range("Index out of bounds.");
    }
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
    const int step = 255/colnum;
    std::vector<unsigned int> histogram(colnum, 0);
    for (const auto pixel:pixels) {
        int index = pixel / step;
        if (index >= colnum) index = colnum - 1;
        histogram[index]++;
    }
    return histogram;
}
