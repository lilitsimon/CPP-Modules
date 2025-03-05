#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    Array() : _data(NULL), _size(0) {}

    Array(unsigned int n) : _size(n){
        _data = new T[n];
    }

    Array(const Array& other) : _size(other.size) {
        _data = new T[_size];
        for (unisgned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
};


#endif
