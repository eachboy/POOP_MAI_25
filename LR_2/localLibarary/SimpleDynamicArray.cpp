#include <iostream>
#include "SimpleDynamicArray.hpp"

namespace SimpleDynamicArray {

    void resize(SimpleDynamicArray* array, unsigned int capacity)
    {
        if (capacity < array->capacity) return;
 
        TestData* temp = array->arr;
        array->arr = new TestData[capacity];

        for (int i = 0; i < array->size; i++) {
            for (size_t j = 0; j < DATA_SIZE; j++) {
                (array->arr + i)->data[j] = (temp + i)->data[j];
            }
            for (size_t j = 0; j < NAME_SIZE; j++) {
                (array->arr + i)->name[j] = (temp + i)->name[j];
            }
        }

        delete[] temp;
        array->capacity = capacity;
    }

    void at(SimpleDynamicArray* array, int index) 
    {
        std::cout << "Data at index " << index << ":\n";
        for (size_t i = 0; i < DATA_SIZE; i++) {
            std::cout << (array->arr + index)->data[i] << " ";
        }
        std::cout << "\nName: " << (array->arr + index)->name;
    }

    void push_back(SimpleDynamicArray* array, int element)
    {
        if (array->size == array->capacity) resize(array, array->capacity*2);

        for (size_t i = 0; i < DATA_SIZE; i++) {
            (array->arr + array->size)->data[i] = element;
        }
        sprintf((array->arr + array->size)->name, "Element_%d", array->size);

        array->size++;
    }

    void push_front(SimpleDynamicArray* array, int element)
    {
        if (array->size == array->capacity) resize(array, array->capacity*2);

        // Сдвигаем все элементы вправо
        for (int i = array->size; i > 0; i--) {
            for (size_t j = 0; j < DATA_SIZE; j++) {
                (array->arr + i)->data[j] = (array->arr + i - 1)->data[j];
            }
            for (size_t j = 0; j < NAME_SIZE; j++) {
                (array->arr + i)->name[j] = (array->arr + i - 1)->name[j];
            }
        }

        // Добавляем новый элемент в начало
        for (size_t j = 0; j < DATA_SIZE; j++) {
            (array->arr)->data[j] = element;
        }
        sprintf((array->arr)->name, "Element_front");

        array->size++;
    }

    void insert(SimpleDynamicArray* array, int index, int element)
    {
        if (array->size == array->capacity) resize(array, array->capacity*2);
        if ((index < 0) || (index > array->size)) {
            std::cout << "Index out of bounds";
            return;
        }

        // Сдвигаем элементы после index вправо
        for (int i = array->size; i > index; i--) {
            for (size_t j = 0; j < DATA_SIZE; j++) {
                (array->arr + i)->data[j] = (array->arr + i - 1)->data[j];
            }
            for (size_t j = 0; j < NAME_SIZE; j++) {
                (array->arr + i)->name[j] = (array->arr + i - 1)->name[j];
            }
        }

        // Вставляем новый элемент
        for (size_t j = 0; j < DATA_SIZE; j++) {
            (array->arr + index)->data[j] = element;
        }
        sprintf((array->arr + index)->name, "Element_%d", index);

        array->size++;
    }

    void concatenate(SimpleDynamicArray* array1, const SimpleDynamicArray* array2)
    {
        // Проверяем, нужно ли увеличить capacity для array1
        if (array1->size + array2->size > array1->capacity) {
            resize(array1, array1->size + array2->size);
        }

        // Копируем элементы из array2 в конец array1
        for (unsigned int i = 0; i < array2->size; i++) {
            // Копируем данные
            for (size_t j = 0; j < DATA_SIZE; j++) {
                (array1->arr + array1->size + i)->data[j] = (array2->arr + i)->data[j];
            }
            // Копируем имя
            for (size_t j = 0; j < NAME_SIZE; j++) {
                (array1->arr + array1->size + i)->name[j] = (array2->arr + i)->name[j];
            }
        }

        // Обновляем размер первого массива
        array1->size += array2->size;
    }

    void count(SimpleDynamicArray* array)
    {
        std::cout << "Size of array: " << array->size;
    }

    void pop_back(SimpleDynamicArray* array)
    {
        if (array->size > 0) {
            array->size--;
        }
    }

    void pop_front(SimpleDynamicArray* array)
    {
        if (array->size == 0) return;

        // Сдвигаем все элементы влево
        for (unsigned int i = 0; i < array->size - 1; i++) {
            for (size_t j = 0; j < DATA_SIZE; j++) {
                (array->arr + i)->data[j] = (array->arr + i + 1)->data[j];
            }
            for (size_t j = 0; j < NAME_SIZE; j++) {
                (array->arr + i)->name[j] = (array->arr + i + 1)->name[j];
            }
        }

        array->size--;
    }

    void pop_out(SimpleDynamicArray* array, int index)
    {
        if ((index < 0) || (index >= array->size)) {
            std::cout << "Index out of bounds";
            return;
        }

        // Сдвигаем элементы после index влево
        for (unsigned int i = index; i < array->size - 1; i++) {
            for (size_t j = 0; j < DATA_SIZE; j++) {
                (array->arr + i)->data[j] = (array->arr + i + 1)->data[j];
            }
            for (size_t j = 0; j < NAME_SIZE; j++) {
                (array->arr + i)->name[j] = (array->arr + i + 1)->name[j];
            }
        }

        array->size--;
    }

    void replace(SimpleDynamicArray* array, int index, int element)
    {
        if ((index < 0) || (index >= array->size)) {
            std::cout << "Index out of bounds";
            return;
        }

        for (size_t j = 0; j < DATA_SIZE; j++) {
            (array->arr + index)->data[j] = element;
        }
        sprintf((array->arr + index)->name, "Element_%d_replaced", index);
    }

    void swap(SimpleDynamicArray* array, int index1, int index2)
    {
        if (index1 < 0 || index2 < 0 || index1 >= array->size || index2 >= array->size) {
            std::cout << "Index out of bounds";
            return;
        }

        TestData temp;
        
        // Копируем первый элемент во временную переменную
        for (size_t j = 0; j < DATA_SIZE; j++) {
            temp.data[j] = (array->arr + index1)->data[j];
        }
        for (size_t j = 0; j < NAME_SIZE; j++) {
            temp.name[j] = (array->arr + index1)->name[j];
        }

        // Копируем второй элемент в первый
        for (size_t j = 0; j < DATA_SIZE; j++) {
            (array->arr + index1)->data[j] = (array->arr + index2)->data[j];
        }
        for (size_t j = 0; j < NAME_SIZE; j++) {
            (array->arr + index1)->name[j] = (array->arr + index2)->name[j];
        }

        // Копируем временный элемент во второй
        for (size_t j = 0; j < DATA_SIZE; j++) {
            (array->arr + index2)->data[j] = temp.data[j];
        }
        for (size_t j = 0; j < NAME_SIZE; j++) {
            (array->arr + index2)->name[j] = temp.name[j];
        }
    }

    void print(SimpleDynamicArray* array)
    {
        std::cout << "Data:\n";
        for(unsigned int i = 0; i < array->size; i++) {
            std::cout << "Element " << i << ":\n";
            std::cout << "Name: " << (array->arr + i)->name << "\n";
            std::cout << "First few data values: ";
            for(size_t j = 0; j < std::min(size_t(5), DATA_SIZE); j++) {
                std::cout << (array->arr + i)->data[j] << " ";
            }
            std::cout << "...\n";
        }
    }

}