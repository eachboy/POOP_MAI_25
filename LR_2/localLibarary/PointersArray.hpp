#ifndef PA_HPP
#define PA_HPP

#include <iostream>

namespace PointersArray
{   
    const size_t DATA_SIZE = 5000;  // Добавляем константу размера данных
    const size_t NAME_SIZE = 100;   // Добавляем константу размера имени
    
    struct TestData
    {
        double data[DATA_SIZE];
        char name[NAME_SIZE];
    };
    

    struct PointersArray
    {
        unsigned int size; //фактический размер
        unsigned int capacity; //максимальный размер
        TestData* arr; //индекс на первый элемент
    };

    void at(PointersArray*, int index);

    void push_back(PointersArray*, int element);
    void push_front(PointersArray*, int element);
    void insert(PointersArray*, int index, int element);
    void concatenate(PointersArray*, const PointersArray*);

    void count(PointersArray*);

    void pop_back(PointersArray*);
    void pop_front(PointersArray*);
    void pop_out(PointersArray*, int index);
    void replace(PointersArray*, int index, int newValue);
    void swap(PointersArray*, int index1, int index2);
    void print(const PointersArray*);
    void move(PointersArray*, int index);
}

#endif
