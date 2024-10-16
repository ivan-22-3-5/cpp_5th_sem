#include <iostream>
#include "Image.h"
void print_image(const Image& image);

int main() {
    Image image1(640, 640);

    for (unsigned int y = 0; y < image1.get_height(); y++) {
        for (unsigned int x = 0; x < image1.get_width(); x++) {
            image1.set_pixel(x, y, rand() % 256);
        }
    }

    image1.save_as_file("file1");

    return EXIT_SUCCESS;
}

void print_image(const Image& image) {
    for (unsigned int y = 0; y < image.get_height(); y++) {
        for (unsigned int x = 0; x < image.get_width(); x++) {
            std::cout << image.get_pixel(x, y) << " ";
        }
        std::cout << std::endl;
    }
}
