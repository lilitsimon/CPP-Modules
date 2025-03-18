#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <chrono>
#include <ctime>

class PmergeMe {
private:
    std::vector<int> vec;
    std::deque<int> deq;

    void mergeInsertionSortVector(std::vector<int>& arr);
    void mergeInsertionSortDeque(std::deque<int>& arr);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void processInput(int argc, char* argv[]);
    void sortAndMeasure();
};

#endif

