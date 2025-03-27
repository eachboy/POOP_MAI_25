#ifndef LIST_MY
#define LIST_MY

#include "Data.hpp"

namespace List
{

    struct ListNode
    {
        Data* data;
        ListNode* next;
    };

    struct List
    {
        unsigned int size;
        ListNode* head;
    };

    void printData(Data*);

    List* createList();

    Data* at(List*, unsigned int);
    
    void push_back(List*, Data*);
    void push_front(List*, Data*);
    void insert(List*, unsigned int, Data*);
    
    void concatenate(List*, List*);

    unsigned int count(List*);
    
    Data* pop_back(List*);
    Data* pop_front(List*);
    Data* pop_out(List*, unsigned int);
    void replace(List*, unsigned int, Data*);

    void swap(List*, unsigned int, unsigned int);
    void move(List*, unsigned int, unsigned int);

    void print(List*);
}

#endif