#include <iostream>
#include "Image.h"

void print_image(const Image &image);

int main() {
    Image image(5, 5, 4);

    print_image(image);
    std::cout << std::endl;
    image.save_as_file("file1");

    Image image2("file1.pgm");
    print_image(image2);

    // for (unsigned int number: image.build_histogram(3)) {
    //     std::cout << number << " ";
    // }

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
