#include <iostream>
#include "Image.h"
#include "loaders/PGMImageLoader.h"

void print_image(const Image &image);

int main() {
    PGMImageLoader loader;
    Image image(5, 5, {24, 24, 24}, loader);
    print_image(image);
    image.save_as_file("image");
    Image image2("image", loader);
    print_image(image2);
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
