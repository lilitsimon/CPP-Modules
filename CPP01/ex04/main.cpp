#include "Sed.hpp"

int main (int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Wrong format. Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()){
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }

    if(!processFile(filename, s1, s2)) {
        return 1;
    }
    std::cout <<"File processed successfully. Output written to " << filename << ".replace" << std::endl;
    return 0;
}



