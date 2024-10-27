#include <format>
#include <map>
#include <sstream>
#include <vector>

#include "stringtools.h"
#include "filenames_parser.h"

std::map<std::string, std::vector<std::string> > parse_filenames(char *filenames[], const int n) {
    std::map<std::string, std::vector<std::string> > files;
    for (int i = 0; i < n; ++i) {
        std::string arg = filenames[i];
        if (auto tokens = split_string(arg, '.'); tokens.size() != 2) {
            throw std::runtime_error("Wrong format of filename!");
        } else {
            files[tokens[1]].push_back(tokens[0]);
        }
    }
    return files;
}