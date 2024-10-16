#include <iostream>
#include "Image.h"
void print_image(const Image& image);

int main() {
    Image image(15, 10);

    for (unsigned int y = 0; y < image.get_height(); y++) {
        for (unsigned int x = 0; x < image.get_width(); x++) {
            image.set_pixel(x, y, 255);
        }
    }

    print_image(image);
    print_image(Image(15, 10, 0));

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
