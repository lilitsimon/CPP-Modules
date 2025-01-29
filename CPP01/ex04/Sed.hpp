#ifndef SED_CPP
#define SED_CPP

#include <string>
#include <iostream>
#include <fstream>

std:: string replaceAll(const std::string &content, const std::string &s1, std::string &s2);

bool processFile(const std::string &filename, const std::string &s1, const std::string &s2);

#endif
