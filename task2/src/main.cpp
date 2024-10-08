#include <iostream>
#include <map>
#include <sstream>
#include <vector>

std::vector<std::string> split_string(const std::string &str, char delimiter);

int main(const int argc, char *argv[]) {
    std::map<std::string, std::vector<std::string> > files;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (auto tokens = split_string(arg, '.'); tokens.size() != 2) {
            return EXIT_FAILURE;
        }else {
            files[tokens[1]].push_back(tokens[0]);
        }
    }

    for (const auto &extension : files) {
        std::cout << extension.first << " ";
        for (const auto &file : extension.second) {
            std::cout << file << " ";
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}

std::vector<std::string> split_string(const std::string &str, const char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(str);

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}
