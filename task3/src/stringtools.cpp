#include "stringtools.h"
#include <sstream>

std::vector<std::string> split_string(const std::string &str, const char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(str);

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

std::string join(const std::vector<std::string>& elements, const std::string& delimiter) {
    std::ostringstream result;
    for (size_t i = 0; i < elements.size(); ++i) {
        result << elements[i];
        if (i != elements.size() - 1) {
            result << delimiter + " ";
        }
    }
    return result.str();
}