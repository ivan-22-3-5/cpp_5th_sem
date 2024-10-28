#include <iostream>
#include <random>

#include "Image.h"
#include "loaders/PPMImageLoader.h"


void print_image(const Image &image);

Pixel generate_random_pixel() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned char> dist(0, 225);
    return {dist(gen), dist(gen), dist(gen)};
}

int main() {
    PPMImageLoader PPM_loader;
    Image image(600, 600, {255, 4, 0}, PPM_loader);

    for (unsigned int y = 0; y < image.get_height(); y++) {
        for (unsigned int x = 0; x < image.get_width(); x++) {
            image.set_pixel(x, y, generate_random_pixel());
        }
    }
    image.save_as_file("image");

    return EXIT_SUCCESS;
}

void print_image(const Image &image) {
    for (unsigned int y = 0; y < image.get_height(); y++) {
        for (unsigned int x = 0; x < image.get_width(); x++) {
            auto [red, green, blue] = image.get_pixel(x, y);
            printf("%d %d %d  ", red, green, blue);
        }
        std::cout << std::endl;
    }
}
