#include <format>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include "stringtools.h"

std::map<std::string, std::vector<std::string> > parse_filenames(char *filenames[], int n);

int main(const int argc, char *argv[]) {
    std::vector<std::string> total;
    std::cout << "Files: " << std::endl;
    for (const auto &[extension, filenames]: parse_filenames(argv+1, argc-1)) {
        total.push_back(
            std::format("{} {} ", filenames.size(), extension) + (filenames.size() == 1 ? "file" : "files"));
        std::cout << "    " << extension << ": " << join(filenames, ",") << std::endl;
    }
    std::cout << "Total: " << join(total, ",") << std::endl;
    return EXIT_SUCCESS;
}
