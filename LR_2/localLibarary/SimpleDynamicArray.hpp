#ifndef SDA_HPP
#define SDA_HPP

#include <iostream>

namespace SimpleDynamicArray
{   
    const size_t DATA_SIZE = 5000;  // Добавляем константу размера данных
    const size_t NAME_SIZE = 100;   // Добавляем константу размера имени
    
    struct TestData
    {
        double data[DATA_SIZE];
        char name[NAME_SIZE];
    };
    

    struct SimpleDynamicArray
    {
        unsigned int size; //фактический размер
        unsigned int capacity; //максимальный размер
        TestData* arr; //индекс на первый элемент
    };

    void at(SimpleDynamicArray*, int index);

    void push_back(SimpleDynamicArray*, int element);
    void push_front(SimpleDynamicArray*, int element);
    void insert(SimpleDynamicArray*, int index, int element);
    void concatenate(SimpleDynamicArray*, const SimpleDynamicArray*);

    void count(SimpleDynamicArray*);

    void pop_back(SimpleDynamicArray*);
    void pop_front(SimpleDynamicArray*);
    void pop_out(SimpleDynamicArray*, int index);
    void replace(SimpleDynamicArray*, int index, int newValue);
    void swap(SimpleDynamicArray*, int index1, int index2);
    void print(const SimpleDynamicArray*);
    void move(SimpleDynamicArray*, int index);
}

#endif
