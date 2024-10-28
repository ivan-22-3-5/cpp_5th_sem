#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include <vector>

#include "loaders/ImageLoader.h"
#include "Pixel.h"

class Image {
public:
    explicit Image(const std::string& filename, ImageLoader &loader);
    Image(unsigned int width, unsigned int height, ImageLoader &loader);
    Image(unsigned int width, unsigned int height, const Pixel &fill_with, ImageLoader &loader);

    void set_loader(const ImageLoader &loader) const;

    [[nodiscard]] unsigned int get_width() const;
    [[nodiscard]] unsigned int get_height() const;

    [[nodiscard]] Pixel get_pixel(unsigned int x, unsigned int y) const;
    void set_pixel(unsigned int x, unsigned int y, Pixel pixel);

    void save_as_file(const std::string& filename) const;

private:
    unsigned int width{};
    unsigned int height{};
    ImageLoader &loader;
    std::vector<Pixel> pixels;
};


#endif
