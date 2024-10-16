#include <iostream>
#include "Image.h"

int main() {
    Image image(15, 10);

    for (unsigned int y = 0; y < image.get_height(); y++) {
        for (unsigned int x = 0; x < image.get_width(); x++) {
            image.set_pixel(x, y, 255);
        }
    }

    for (unsigned int y = 0; y < image.get_height(); y++) {
        for (unsigned int x = 0; x < image.get_width(); x++) {
            std::cout << image.get_pixel(x, y) << " ";
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
