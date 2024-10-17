#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include <vector>


class Image {
public:
    explicit Image(const std::string& filename);
    Image(unsigned int width, unsigned int height);
    Image(unsigned int width, unsigned int height, unsigned char filling_value);

    [[nodiscard]] unsigned int get_width() const;
    [[nodiscard]] unsigned int get_height() const;

    [[nodiscard]] unsigned int get_pixel(unsigned int x, unsigned int y) const;
    void set_pixel(unsigned int x, unsigned int y, unsigned char value);

    void save_as_file(const std::string& filename) const;

    [[nodiscard]] std::vector<unsigned int> build_histogram(unsigned char colnum) const;

private:
    unsigned int width{};
    unsigned int height{};
    std::vector<unsigned char> pixels;
};


#endif
