#include <fstream>
#include <iostream>

#include "Image.h"
#include "loaders/ImageLoader.h"

Image::Image(const std::string& filename, ImageLoader &loader) : loader(loader) {
   loader.load(pixels, width, height, filename);
}

Image::Image(const unsigned int width, const unsigned int height, ImageLoader& loader)
    : width(width), height(height), pixels(width * height, Pixel(0, 0, 0)), loader(loader) {
}

Image::Image(unsigned int width, unsigned int height, const Pixel &fill_with, ImageLoader &loader)
    : width(width), height(height), pixels(width * height, fill_with), loader(loader) {
}

unsigned int Image::get_width() const {
    return width;
}

unsigned int Image::get_height() const {
    return height;
}

Pixel Image::get_pixel(const unsigned int x, const unsigned int y) const {
    if (x >= width || y >= height) {
        throw std::out_of_range("Index out of bounds.");
    }
    return pixels.at(y * width + x);
}

void Image::set_pixel(const unsigned int x, const unsigned int y, const Pixel pixel) {
    if (x >= width || y >= height) {
        throw std::out_of_range("Index out of bounds.");
    }
    pixels.at(y * width + x) = pixel;
}

void Image::set_loader(ImageLoader &loader) {
    this->loader = loader;
}

void Image::save_as_file(const std::string& filename) const {
    loader.save_as_file(pixels, width, height, filename);
}
