#include <iostream>
#include "Image.h"

void print_image(const Image &image);

int main() {
    Image image1(10, 10);

    for (unsigned int y = 0; y < image1.get_height(); y++) {
        for (unsigned int x = 0; x < image1.get_width(); x++) {
            image1.set_pixel(x, y, rand() % 256);
        }
    }

    for (unsigned int number: image1.build_histogram(3)) {
        std::cout << number << " ";
    }

    return EXIT_SUCCESS;
}

void print_image(const Image &image) {
    for (unsigned int y = 0; y < image.get_height(); y++) {
        for (unsigned int x = 0; x < image.get_width(); x++) {
            std::cout << image.get_pixel(x, y) << " ";
        }
        std::cout << std::endl;
    }
}
