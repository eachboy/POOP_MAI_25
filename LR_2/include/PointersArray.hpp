#ifndef PTRARRAY
#define PTRARRAY

#include "Data.hpp"

namespace PointersArray
{
    struct PointersArray
    {
        unsigned int capacity;
        unsigned int size;
        Data** data;
    };

    void printData(Data);

    PointersArray* createArray(unsigned int);
    void deleteArray(PointersArray*);

    void resize(PointersArray*, unsigned int);

    Data* at(PointersArray*, unsigned int);
    
    void push_back(PointersArray*, Data*);
    void push_front(PointersArray*, Data*);
    void insert(PointersArray*, unsigned int, Data*);
    
    PointersArray* concatenate(PointersArray*, PointersArray*);

    unsigned int count(PointersArray*);
    
    Data* pop_back(PointersArray*);
    Data* pop_front(PointersArray*);
    Data* pop_out(PointersArray*, unsigned int);
    void replace(PointersArray*, unsigned int, Data*);

    void swap(PointersArray*, unsigned int, unsigned int);
    void move(PointersArray*, unsigned int, unsigned int);

    void print(PointersArray*);
}

#endif