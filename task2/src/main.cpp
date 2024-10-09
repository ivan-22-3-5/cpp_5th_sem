#include <format>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

std::vector<std::string> split_string(const std::string &str, char delimiter);
std::map<std::string, std::vector<std::string> > parse_args(int argc, char *argv[]);
std::string join(const std::vector<std::string>& elements, const std::string& delimiter);

int main(const int argc, char *argv[]) {
    std::vector<std::string> output;
    for (const auto &[extension, filenames]: parse_args(argc, argv)) {
        output.push_back(std::format("{} {} ", filenames.size(), extension) + (filenames.size() == 1 ? "file" : "files"));
        std::cout << extension << " ";
        for (const auto &filename: filenames) {
            std::cout << filename << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Received: " << join(output, ", ") << std::endl;
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

std::string join(const std::vector<std::string>& elements, const std::string& delimiter) {
    std::ostringstream result;
    for (size_t i = 0; i < elements.size(); ++i) {
        result << elements[i];
        if (i != elements.size() - 1) {
            result << delimiter;
        }
    }
    return result.str();
}