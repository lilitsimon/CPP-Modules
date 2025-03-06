#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)  {
    if(this!= &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if(_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full, cannot add more numbers");
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if(_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate the span");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() -1; i++)
        minSpan = std::min(minSpan, sorted[i + 1] - sorted[i]);

    return minSpan;
}

int Span::longestSpan() const {
    if(_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate the span");
    return *std::max_element(_numbers.begin(), _numbers.end()) 
    - *std::min_element(_numbers.begin(), _numbers.end());
}

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    if(std::distance(begin, end) > static_cast<int>(_maxSize - _numbers.size()))
        throw std::runtime_error("Not enough space to add all numbers");
    _numbers.insert(_numbers.end(), begin, end);
}

void Span::printNumbers() const {
    std::cout << "Numbers: ";
    for (size_t i = 0; i < _numbers.size(); i++)
        std::cout << _numbers[i] << " " << std::endl;
}
