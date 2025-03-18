#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    PmergeMe sorter;
    sorter.processInput(argc, argv);
    sorter.sortAndMeasure();
    return 0;
}
