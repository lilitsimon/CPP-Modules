#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other ) {
    this->vec = other.vec;
    this->deq = other.deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->vec = other.vec;
        this->deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::processInput(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No numbers provided" << std::endl;
        exit(1);
    }
    for (int i = 1; i < argc; i++) {
        std::istringstream iss(argv[i]);
        int num;

        if(!(iss >> num) || num <= 0) {
            std::cerr << "Error: Invalud Input -> " << argv[i] << std::endl;
            exit(1);
        }

        vec.push_back(num);
        deq.push_back(num);
    }
}

void PmergeMe::mergeInsertionSortVector(std::vector<int>& arr) {
    if (arr.size() <= 1)
        return;
    
    std::vector<int> sorted;
    sorted.push_back(arr[0]);

    for(size_t i= 1; i < arr.size(); i++) {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), arr[i]);
        sorted.insert(pos, arr[i]);
    }

    arr = sorted;
}
void PmergeMe::mergeInsertionSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1)
        return;
    
    std::deque<int> sorted;
    sorted.push_back(arr[0]);

    for(size_t i= 1; i < arr.size(); i++) {
        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), arr[i]);
        sorted.insert(pos, arr[i]);
    }

    arr = sorted;
}

void PmergeMe::sortAndMeasure() {
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::clock_t startVec = std::clock();
    mergeInsertionSortVector(vec);
    std::clock_t endVec = std::clock();
    double durationVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1e6;

    std::clock_t startDeq = std::clock();
    mergeInsertionSortDeque(deq);
    std::clock_t endDeq = std::clock();
    double durationDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process " << vec.size() << " elements with std::vector: " << durationVec << " us" << std::endl;
    std::cout << "Time to process " << deq.size() << " elements with std::deque: " << durationDeq << " us" << std::endl;
}
