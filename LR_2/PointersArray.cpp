#include "include/PointersArray.hpp"
#include <iostream>

namespace PointersArray
{
    void printData(Data* data)
    {
        std::cout << "name: " << data->name << ", data: " << data->data << '\n';
    }

    PointersArray* createArray(unsigned int capacity)
    {
        PointersArray* array = new PointersArray();

        array->capacity = capacity;
        array->size = 0;
        array->data = new Data*[capacity] { 0 };

        return array;
    }

    void deleteArray(PointersArray* array)
    {
        delete[] array->data;
        delete array;
    }

    void resize(PointersArray* array, unsigned int capacity)
    {
        if (capacity < array->capacity)
        {
            std::cout << "Error: capacity is less than current capacity" << std::endl;
            return;
        }

        Data** temp = array->data;
        
        array->data = new Data*[capacity];
        for (int i = 0; i < array->size; i++)
        {
            *(array->data + i) = *(temp + i);
        }

        delete[] temp;
    }

    // Returns old capacity array
    Data** resizeNoCopy(PointersArray* array, unsigned int capacity)
    {
        if (capacity < array->capacity)
        {
            return nullptr;
        }

        Data** temp = array->data;
        
        array->data = new Data*[capacity];

        return temp;
    }

    void resizeIfOut(PointersArray* array)
    {
        if (array->size >= array->capacity)
        {
            resize(array, array->capacity * 2);
        }
    }

    Data* at(PointersArray* array, unsigned int i)
    {
        return *(array->data + i);
    }

    void push_back(PointersArray* array, Data* data)
    {
        unsigned int capacity = array->capacity;
        unsigned int size = array->size;

        resizeIfOut(array);

        *(array->data + size) = data;
        array->size++;
    }

    void push_front(PointersArray* array, Data* data)
    {
        unsigned int capacity = array->capacity;
        unsigned int size = array->size;
        Data** temp;

        if (size >= capacity)
        {
            temp = resizeNoCopy(array, capacity * 2);
        }
        else
        {
            temp = array->data;
            array->data = new Data*[capacity];
        }

        *array->data = data;
        for (int i = 0; i < size; i++)
        {
            *(array->data + i + 1) = *(temp + i);
        }

        array->size++;
    }

    void insert(PointersArray* array, unsigned int index, Data* data)
    {
        unsigned int capacity = array->capacity;
        unsigned int size = array->size;
        Data** temp;

        if (size >= capacity)
        {
            temp = resizeNoCopy(array, capacity * 2);
        }
        else
        {
            temp = array->data;
            array->data = new Data*[capacity];
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
    
    PointersArray* concatenate(PointersArray* arr1, PointersArray* arr2)
    {
        PointersArray* newArray = createArray(arr1->capacity + arr2->capacity);
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

    unsigned int count(PointersArray* array)
    {
        return array->size;
    }
    
    Data* pop_back(PointersArray* array)
    {
        array->size--;
        return *(array->data + (array->size - 1));
    }

    Data* pop_front(PointersArray* array)
    {
        Data** temp = array->data;
        array->data = new Data*[array->capacity];

        array->size--;

        for (int i = 0; i < array->size; i++)
        {
            *(array->data + i) = *(temp + i + 1);
        }

        Data* toReturn = *temp;

        delete[] temp;

        return toReturn;
    }

    Data* pop_out(PointersArray* array, unsigned int index)
    {
        Data** temp = array->data;
        array->data = new Data*[array->capacity];

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

        Data* toReturn = *(temp + index);

        delete[] temp;

        return toReturn;
    }

    void replace(PointersArray* array, unsigned int i, Data* data)
    {
        *(array->data + i) = data;
    }

    void swap(PointersArray* array, unsigned int i, unsigned int j)
    {
        Data* temp = *(array->data + i);
        *(array->data + i) = *(array->data + j);
        *(array->data + j) = temp;
    }

    void move(PointersArray* array, unsigned int from, unsigned int to)
    {
        insert(array, to, pop_out(array, from));
    }

    void print(PointersArray* array)
    {
        for (int i = 0; i < array->size; i++)
        {
            printData(*(array->data + i));
        }

        std::cout << std::endl;
    }
}