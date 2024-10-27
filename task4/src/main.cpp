#include <iostream>
#include <random>
#include "Image.h"

void print_image(const Image &image);

int generate_random_int(const int min, const int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(min, max);
    return dist(gen);
}

int main() {
    const Image image(5, 5, 4);

    std::cout << "Image before saving:" << std::endl;
    print_image(image);
    std::cout << std::endl;
    image.save_as_file("file1");

    const Image image2("file1.pgm");
    std::cout << "Image after reading from file:" << std::endl;
    print_image(image2);
    std::cout << std::endl;

    Image image3(500, 500, 0);
    for (unsigned int y = 0; y < image3.get_height(); y++) {
        for (unsigned int x = 0; x < image3.get_width(); x++) {
            image3.set_pixel(x, y, generate_random_int(0, 255));
        }
    }

    std::cout << "Histogram: ";
    for (const unsigned int number: image3.build_histogram(3)) {
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
