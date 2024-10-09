#include <format>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include "stringtools.h"

std::map<std::string, std::vector<std::string> > parse_args(int argc, char *argv[]);

int main(const int argc, char *argv[]) {
    std::vector<std::string> total;
    std::cout << "Files: " << std::endl;
    for (const auto &[extension, filenames]: parse_args(argc, argv)) {
        total.push_back(
            std::format("{} {} ", filenames.size(), extension) + (filenames.size() == 1 ? "file" : "files"));
        std::cout << "    " << extension << ": " << join(filenames, ",") << std::endl;
    }
    std::cout << "Total: " << join(total, ",") << std::endl;
    return EXIT_SUCCESS;
}

std::map<std::string, std::vector<std::string> > parse_args(const int argc, char *argv[]) {
    std::map<std::string, std::vector<std::string> > files;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (auto tokens = split_string(arg, '.'); tokens.size() != 2) {
            throw std::runtime_error("Wrong format of filename!");
        } else {
            files[tokens[1]].push_back(tokens[0]);
        }
    }
    return files;
}
