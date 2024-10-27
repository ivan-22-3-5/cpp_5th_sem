#include <format>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <cassert>

#include "filenames_parser.h"

void test_parse_filenames() {
    // Test 1: Valid filenames
    {
        const int n = 3;
        char* filenames[] = {"file1.txt", "file2.cpp", "file3.txt" };
        auto result = parse_filenames(filenames, n);

        const auto txt = std::vector<std::string>{"file1", "file3"};
        const auto cpp = std::vector<std::string>{"file2"};
        assert(result["txt"] == txt);
        assert(result["cpp"] == cpp);
    }

    // Test 2: Invalid filename format (no extension)
    {
        const int n = 2;
        char* filenames[] = {"file1", "file2.cpp" };
        try {
            auto result = parse_filenames(filenames, n);
            assert(false);
        } catch (const std::runtime_error& e) {
            assert(std::string(e.what()) == "Wrong format of filename!");
        }
    }

    // Test 3: Invalid filename format (multiple dots)
    {
        const int n = 2;
        char* filenames[] = { "file1.ver1.txt", "file2.cpp" };
        try {
            auto result = parse_filenames(filenames, n);
            assert(false);
        } catch (const std::runtime_error& e) {
            assert(std::string(e.what()) == "Wrong format of filename!");
        }
    }

    // Test 4: Empty array of filenames (edge case)
    {
        const int n = 0;
        char* filenames[] = { };
        auto result = parse_filenames(filenames, n);
        assert(result.empty());
    }

    std::cout << "All tests passed!" << std::endl;
}

int main(const int argc, char *argv[]) {
    test_parse_filenames();
    return EXIT_SUCCESS;
}
