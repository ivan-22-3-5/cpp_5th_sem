#ifndef FILENAMES_PARSER_H
#define FILENAMES_PARSER_H
#include <format>
#include <map>
#include <vector>

std::map<std::string, std::vector<std::string> > parse_filenames(char *filenames[], int n);
#endif
