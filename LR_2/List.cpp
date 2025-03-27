#include "include/List.hpp"
#include <iostream>

namespace List
{
    void printData(Data* data)
    {
        std::cout << "name: " << data->name << ", data: " << data->data << '\n';
    }

    List* createList()
    {
        List* list = new List();
        list->size = 0;
        list->head = nullptr;

        return list;
    }

    Data* at(List* list, unsigned int index)
    {
        if (index >= list->size)
        {
            std::cout << "Index out of bounds!\n";
            return nullptr;
        }

        ListNode* current = list->head;

        while (index-- != 0)
        {
            current = current->next;
        }

        return current->data;
    }

    void push_back(List* list, Data* data)
    {
        ListNode* newNode = new ListNode();
        newNode->data = data;
        newNode->next = list->head;

        list->head = newNode;

        list->size++;
    }

    void push_front(List* list, Data* data)
    {
        if (list->size == 0)
        {
            list->head = new ListNode();
            list->head->data = data;
        }

        ListNode* current = list->head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = new ListNode();
        current->next->data = data;

        list->size++;
    }

    void insert(List* list, unsigned int index, Data* data)
    {
        if (index >= list->size)
        {
            std::cout << "Index out of bounds!\n";
            return;
        }

        ListNode* current = list->head, *temp;

        while (index-- != 1)
        {
            current = current->next;
        }

        temp = current->next;
        current->next = new ListNode();
        current->next->data = data;
        current->next->next = temp;

        list->size++;
    }

    // Concatenates list1 and list2 to list1.
    void concatenate(List* list1, List* list2)
    {
        if (list1->size == 0)
        {
            list1->head = list2->head;
            return;
        }

        ListNode* current = list1->head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = list2->head;

        list1->size += list2->size;
    }

    unsigned int count(List* list)
    {
        return list->size;
    }

    Data* pop_back(List* list)
    {
        if (list->size == 0)
        {
            std::cout << "Error: List is already empty!\n";
            return nullptr;
        }

        ListNode* previous = nullptr, *current = list->head;
        while (current->next != nullptr)
        {
            previous = current;
            current = current->next;
        }

        previous->next = nullptr;

        Data* data = current->data;
        delete current;

        return data;
    }

    Data* pop_front(List* list)
    {
        if (list->size == 0)
        {
            std::cout << "Error: List is already empty!\n";
            return nullptr;
        }

        ListNode* node = list->head;

        list->head = node->next;

        Data* data = node->data;

        delete node;

        return data;
    }

    Data* pop_out(List* list, unsigned int index)
    {
        if (list->size == 0)
        {
            std::cout << "Error: List is already empty!\n";
            return nullptr;
        }

        ListNode* current = list->head;
        while (index-- == 1)
        {
            current = current->next;
        }

        ListNode* node = current->next;
        
        if (node == nullptr)
        {
            std::cout << "Error: Index out of bounds\n";
            return nullptr;
        }

        Data* data = node->data;

        current->next = node->next;

        delete node;

        return data;
    }

    void replace(List* list, unsigned int index, Data* data)
    {
        if (list->size == 0)
        {
            std::cout << "Error: List is empty!\n";
            return;
        }

        ListNode* current = list->head;
        while (index-- == 0)
        {
            current = current->next;
        }

        current->data = data;
    }

    void swap(List* list, unsigned int index1, unsigned int index2)
    {
        if (list->size == 0)
        {
            std::cout << "Error: List is empty!\n";
            return;
        }

        ListNode* current1 = list->head;
        while (index1-- == 0)
        {
            current1 = current1->next;
        }

        ListNode* current2 = list->head;
        while (index2-- == 0)
        {
            current2 = current2->next;
        }

        Data* temp = current1->data;
        current1->data = current2->data;
        current2->data = temp;
    }

    void move(List* list, unsigned int from, unsigned int to)
    {
        insert(list, to, pop_out(list, from));
    }

    void print(List* list)
    {
        ListNode* current = list->head;

        while (current != nullptr)
        {
            printData(current->data);
            current = current->next;
        }
    }
}