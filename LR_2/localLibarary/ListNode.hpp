#ifndef LN_HPP
#define LN_HPP

#include <iostream>

namespace ListNode
{   
    const size_t DATA_SIZE = 5000;  // Добавляем константу размера данных
    const size_t NAME_SIZE = 100;   // Добавляем константу размера имени
    
    struct TestData
    {
        double data[DATA_SIZE];
        char name[NAME_SIZE];
    };
    

    struct ListNode
    {
        unsigned int size; //фактический размер
        unsigned int capacity; //максимальный размер
        TestData* arr; //индекс на первый элемент
    };

    void at(ListNode*, int index);

    void push_back(ListNode*, int element);
    void push_front(ListNode*, int element);
    void insert(ListNode*, int index, int element);
    void concatenate(ListNode*, const ListNode*);

    void count(ListNode*);

    void pop_back(ListNode*);
    void pop_front(ListNode*);
    void pop_out(ListNode*, int index);
    void replace(ListNode*, int index, int newValue);
    void swap(ListNode*, int index1, int index2);
    void print(const ListNode*);
    void move(ListNode*, int index);
}

#endif
