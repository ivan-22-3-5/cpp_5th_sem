#ifndef IMAGE_H
#define IMAGE_H
#include <vector>


class Image {
public:
    Image(unsigned int width, unsigned int height);
    Image(unsigned int width, unsigned int height, unsigned char filling_value);

    [[nodiscard]] unsigned int get_width() const;
    [[nodiscard]] unsigned int get_height() const;

    [[nodiscard]] unsigned int get_pixel(unsigned int x, unsigned int y) const;
    void set_pixel(unsigned int x, unsigned int y, unsigned char value);

private:
    unsigned int width;
    unsigned int height;
    std::vector<unsigned char> data;
};


#endif
