#ifndef STRINGTOOLS_H
#define STRINGTOOLS_H
#include <format>
#include <vector>

std::vector<std::string> split_string(const std::string &str, char delimiter);
std::string join(const std::vector<std::string>& elements, const std::string& delimiter);

#endif