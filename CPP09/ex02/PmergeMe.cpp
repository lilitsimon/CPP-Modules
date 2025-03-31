#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
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

        if (!(iss >> num) || num <= 0) {
            std::cerr << "Error" << std::endl;
            exit(1);
        }

        vec.push_back(num);
        deq.push_back(num);
    }
}

void PmergeMe::insertSortedVector(std::vector<int>& arr, int value) {
    std::vector<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), value);
    arr.insert(pos, value);
}

void PmergeMe::insertSortedDeque(std::deque<int>& arr, int value) {
    std::deque<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), value);
    arr.insert(pos, value);
}

void PmergeMe::fordJohnsonVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> pend; // stores the unpaired element in case the array has odd length.

    size_t i = 0;
    while (i + 1 < arr.size()) {
        if (arr[i] < arr[i + 1])
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        else
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        i += 2;
    }
    if (i < arr.size()) // the upnpaired element
        pend.push_back(arr[i]);

    std::vector<int> mainChain; //  building the main chain by extracting the larger value from each pair.
    for (size_t j = 0; j < pairs.size(); j++)
        mainChain.push_back(pairs[j].first);

    fordJohnsonVector(mainChain);

    for (size_t j = 0; j < pairs.size(); j++)
        insertSortedVector(mainChain, pairs[j].second);

    for (size_t j = 0; j < pend.size(); j++)
        insertSortedVector(mainChain, pend[j]);

    arr = mainChain;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    std::deque<std::pair<int, int> > pairs;
    std::deque<int> pend;

    size_t i = 0;
    while (i + 1 < arr.size()) {
        if (arr[i] < arr[i + 1])
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        else
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        i += 2;
    }
    if (i < arr.size())
        pend.push_back(arr[i]);

    std::deque<int> mainChain;
    for (size_t j = 0; j < pairs.size(); j++)
        mainChain.push_back(pairs[j].first);

    fordJohnsonDeque(mainChain);

    for (size_t j = 0; j < pairs.size(); j++)
        insertSortedDeque(mainChain, pairs[j].second);

    for (size_t j = 0; j < pend.size(); j++)
        insertSortedDeque(mainChain, pend[j]);

    arr = mainChain;
}

void PmergeMe::sortAndMeasure() {
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::clock_t startVec = std::clock();
    fordJohnsonVector(vec);
    std::clock_t endVec = std::clock();
    double durationVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1e6;

    std::clock_t startDeq = std::clock();
    fordJohnsonDeque(deq);
    std::clock_t endDeq = std::clock();
    double durationDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process " << vec.size() << " elements with std::vector: " << durationVec << " us" << std::endl;
    std::cout << "Time to process " << deq.size() << " elements with std::deque: " << durationDeq << " us" << std::endl;
}
