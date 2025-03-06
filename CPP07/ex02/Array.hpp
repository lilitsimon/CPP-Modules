#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    Array() : _data(NULL), _size(0) {}

    Array(unsigned int n) : _size(n){
        _data = new T[n]; // allocates n elements of type T
    }

    Array(const Array& other) : _size(other._size) {
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }

    Array& operator = (const Array& other) {
        if(this != &other){
            delete[] _data; // deleting old memory before copying new values
            _size = other._size;
            _data = new T[_size];
             for(unsigned int i = 0; i < _size; i++) // element by element copy
                _data[i] = other._data[i];
        }
        return *this;
    }

    ~Array() {
        delete[] _data;
    }

    T& operator[](unsigned int index) { // overloads the [] operator, allowing us to access array elements using arr[i].
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    const T& operator[](unsigned int index) const { // allows the operator[] to be called on a const object.
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    unsigned int size() const {
        return _size;
    }
};

#endif
