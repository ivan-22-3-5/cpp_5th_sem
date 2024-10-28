#include <fstream>
#include <iostream>

#include "PPMImageLoader.h"

void PPMImageLoader::save_as_file(const std::vector<Pixel>& pixels, unsigned int width, unsigned int height, const std::string &filename) {
    std::ofstream file(filename + ".ppm", std::ios::binary);
    if (!file) {
        std::cerr << "Error: File could not be opened." << std::endl;
    }
    file << "P3\n" << width << " " << height << "\n" << "255\n";
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            auto [red, green, blue] = pixels.at(y * width + x);
            file << static_cast<int>(red) << " " << static_cast<int>(green) << " " << static_cast<int>(blue) << " " ;
        }
        file << "\n";
    }
    file.close();
}

void PPMImageLoader::load(std::vector<Pixel>& pixels, unsigned int &width, unsigned int &height, const std::string &filename) {
    std::ifstream file(filename + ".ppm", std::ios::binary);
    if (!file) {
        throw std::runtime_error("File could not be opened.");
    }

    std::string magic_number;
    file >> magic_number;
    if (magic_number != "P3") {
        throw std::runtime_error("Unsupported file format.");
    }

    char ch;
    file >> ch;
    while (ch == '#') {
        std::string comment_line;
        std::getline(file, comment_line);
        file >> ch;
    }
    file.unget();

    file >> width >> height;
    pixels.resize(width * height);
    file.ignore(4);
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            Pixel pixel;
            file >> pixel.red >> pixel.green >> pixel.blue;
            pixels.at(y * width + x)=pixel;
        }
    }
    file.close();
}
