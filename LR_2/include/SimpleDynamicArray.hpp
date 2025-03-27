#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP

#include "Data.hpp"

namespace SimpleDynamicArray
{
    struct SimpleDynamicArray
    {
        unsigned int capacity;
        unsigned int size;
        Data* data;
    };

    void printData(Data);

    SimpleDynamicArray* createArray(unsigned int);
    void deleteArray(SimpleDynamicArray*);

    void resize(SimpleDynamicArray* array, unsigned int add);

    Data at(SimpleDynamicArray*, unsigned int);
    
    void push_back(SimpleDynamicArray*, Data);
    void push_front(SimpleDynamicArray*, Data);
    void insert(SimpleDynamicArray*, unsigned int, Data);
    
    SimpleDynamicArray* concatenate(SimpleDynamicArray*, SimpleDynamicArray*);

    unsigned int count(SimpleDynamicArray*);
    
    Data pop_back(SimpleDynamicArray*);
    Data pop_front(SimpleDynamicArray*);
    Data pop_out(SimpleDynamicArray*, unsigned int);
    void replace(SimpleDynamicArray*, unsigned int, Data);

    void swap(SimpleDynamicArray*, unsigned int, unsigned int);
    void move(SimpleDynamicArray*, unsigned int, unsigned int);

    void print(SimpleDynamicArray*);
}

#endif