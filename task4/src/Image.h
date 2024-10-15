#ifndef IMAGE_H
#define IMAGE_H
#include <vector>


class Image {
public:
    Image(unsigned int width, unsigned int height);

    [[nodiscard]] unsigned int get_width() const;
    [[nodiscard]] unsigned int get_height() const;

private:
    unsigned int width;
    unsigned int height;
    std::vector<unsigned char> data;
};


#endif
