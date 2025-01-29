#include "Sed.hpp"

std::string replaceAll(std::string &content, const std::string &s1, const std::string &s2){
    if (s1.empty())
        return content;
    
    std::string result;
    size_t pos = 0; // to track the current pos in content
    size_t found; // to store the position of the next occ of s1

    while ((found = content.find(s1, pos)) != std::string::npos) /* special const in std::string that represents no ps or invalid pos */ {
        result.append(content, pos, found - pos); // copying the part before the match
        result.append(s2);
        pos = found + s1.length();
    }

    result.append(content, pos, std::string::npos);

    return result;
}

bool processFile(const std::string &filename, const std::string &s1, const std::string &s2){
    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cout << "Error: could not open file " << filename << std::endl;
        return false;
    }

    std::string content;
    std::string line;

    while (std::getline(inputFile, line)) {
        content += line + "\n";
    }
    inputFile.close();

    std::string replacedContent = replaceAll(content, s1, s2);

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile) {
        std::cerr << "Error: could not create file " << filename << ".replace" << std::endl;
            return false;
    }
    outputFile << replacedContent;
    outputFile.close();

    return true;
}
