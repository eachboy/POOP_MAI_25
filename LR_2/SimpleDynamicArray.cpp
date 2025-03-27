#include "include/SimpleDynamicArray.hpp"
#include <iostream>

namespace SimpleDynamicArray
{
    void printData(Data data)
    {
        std::cout << "name: " << data.name << ", data: " << data.data << '\n';
    }

    SimpleDynamicArray* createArray(unsigned int capacity)
    {
        SimpleDynamicArray* array = new SimpleDynamicArray();

        array->capacity = capacity;
        array->size = 0;
        array->data = new Data[capacity] { 0 };

        return array;
    }

    void deleteArray(SimpleDynamicArray* array)
    {
        delete[] array->data;
        delete array;
    }

    void resize(SimpleDynamicArray* array, unsigned int capacity)
    {
        if (capacity < array->capacity)
        {
            std::cout << "Error: capacity is less than current capacity" << std::endl;
            return;
        }

        Data* temp = array->data;
        
        array->data = new Data[capacity];
        for (int i = 0; i < array->size; i++)
        {
            *(array->data + i) = *(temp + i);
        }

        delete[] temp;
    }

    // Returns old capacity array
    Data* resizeNoCopy(SimpleDynamicArray* array, unsigned int capacity)
    {
        if (capacity < array->capacity)
        {
            return nullptr;
        }

        Data* temp = array->data;
        
        array->data = new Data[capacity];

        return temp;
    }

    void resizeIfOut(SimpleDynamicArray* array)
    {
        if (array->size >= array->capacity)
        {
            resize(array, array->capacity * 2);
        }
    }

    Data at(SimpleDynamicArray* array, unsigned int i)
    {
        return *(array->data + i);
    }

    void push_back(SimpleDynamicArray* array, Data data)
    {
        unsigned int capacity = array->capacity;
        unsigned int size = array->size;

        resizeIfOut(array);

        *(array->data + size) = data;
        array->size++;
    }

    void push_front(SimpleDynamicArray* array, Data data)
    {
        unsigned int capacity = array->capacity;
        unsigned int size = array->size;
        Data* temp;

        if (size >= capacity)
        {
            temp = resizeNoCopy(array, capacity * 2);
        }
        else
        {
            temp = array->data;
            array->data = new Data[capacity];
        }

        *array->data = data;
        for (int i = 0; i < size; i++)
        {
            *(array->data + i + 1) = *(temp + i);
        }

        array->size++;
    }

    void insert(SimpleDynamicArray* array, unsigned int index, Data data)
    {
        unsigned int capacity = array->capacity;
        unsigned int size = array->size;
        Data* temp;

        if (size >= capacity)
        {
            temp = resizeNoCopy(array, capacity * 2);
        }
        else
        {
            temp = array->data;
            array->data = new Data[capacity];
        }

        array->size++;

        int i = 0;

        for(; i < index; i++)
        {
            *(array->data + i) = *(temp + i);
        }

        *(array->data + i) = data;

        for(; i < size; i++)
        {
            *(array->data + i + 1) = *(temp + i);
        }
    }
    
    SimpleDynamicArray* concatenate(SimpleDynamicArray* arr1, SimpleDynamicArray* arr2)
    {
        SimpleDynamicArray* newArray = createArray(arr1->capacity + arr2->capacity);
        newArray->size = arr1->size + arr2->size;

        for (int i = 0; i < arr1->size; i++)
        {
            push_back(newArray, *(arr1->data + i));
        }

        for (int i = 0; i < arr2->size; i++)
        {
            push_back(newArray, *(arr2->data + i));
        }
        
        return newArray;
    }

    unsigned int count(SimpleDynamicArray* array)
    {
        return array->size;
    }
    
    Data pop_back(SimpleDynamicArray* array)
    {
        array->size--;
        return *(array->data + (array->size - 1));
    }

    Data pop_front(SimpleDynamicArray* array)
    {
        Data* temp = array->data;
        array->data = new Data[array->capacity];

        array->size--;

        for (int i = 0; i < array->size; i++)
        {
            *(array->data + i) = *(temp + i + 1);
        }

        Data toReturn = *temp;

        delete[] temp;

        return toReturn;
    }

    Data pop_out(SimpleDynamicArray* array, unsigned int index)
    {
        Data* temp = array->data;
        array->data = new Data[array->capacity];

        array->size--;

        int i = 0;
        for(; i < index; i++)
        {
            *(array->data + i) = *(temp + i);
        }

        for (; i <= array->size; i++)
        {
            *(array->data + i) = *(temp + i + 1);
        }

        Data toReturn = *(temp + index);

        delete[] temp;

        return toReturn;
    }

    void replace(SimpleDynamicArray* array, unsigned int i, Data data)
    {
        *(array->data + i) = data;
    }

    void swap(SimpleDynamicArray* array, unsigned int i, unsigned int j)
    {
        Data temp = *(array->data + i);
        *(array->data + i) = *(array->data + j);
        *(array->data + j) = temp;
    }

    void move(SimpleDynamicArray* array, unsigned int from, unsigned int to)
    {
        insert(array, to, pop_out(array, from));
    }

    void print(SimpleDynamicArray* array)
    {
        for (int i = 0; i < array->size; i++)
        {
            printData(*(array->data + i));
        }

        std::cout << std::endl;
    }
}