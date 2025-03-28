#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange btc("data.csv");  // Load database
    btc.processInputFile(argv[1]);    // Process user input file

    return 0;
}
