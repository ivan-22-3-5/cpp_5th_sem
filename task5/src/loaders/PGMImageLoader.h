#ifndef PGMIMAGELOADER_H
#define PGMIMAGELOADER_H

#include "ImageLoader.h"

class PGMImageLoader: public ImageLoader{
public:
    void load(std::vector<Pixel> &pixels, unsigned int &width, unsigned int &height, const std::string &filename) override;
    void save_as_file(const std::vector<Pixel> &pixels, unsigned int width, unsigned int height, const std::string &filename) override;
};

#endif
