#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <ctime>

class PmergeMe {
    private:
        std::vector<int> vec;
        std::deque<int> deq;
    
        void fordJohnsonVector(std::vector<int>& arr);
        void fordJohnsonDeque(std::deque<int>& arr);
    
        void insertSortedVector(std::vector<int>& arr, int value);
        void insertSortedDeque(std::deque<int>& arr, int value);
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
    
        void processInput(int argc, char* argv[]);
        void sortAndMeasure();
    };
    
    #endif
