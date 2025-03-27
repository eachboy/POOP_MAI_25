#include <iostream>
#include <chrono>
#include "include/SimpleDynamicArray.hpp"
#include "include/PointersArray.hpp"

#include "include/Data.hpp"
#include "include/List.hpp"

#include "fstream"

#define TIME_TYPE chrono::microseconds

using namespace std;

struct Timer
{
    int64_t at_time;
    int64_t push_back_time;
    int64_t push_front_time;
    int64_t insert_time;
    int64_t concatenate_time;
    int64_t count_time;
    int64_t pop_back_time;
    int64_t pop_front_time;
    int64_t pop_out_time;
    int64_t replace_time;
    int64_t swap_time;
    int64_t move_time;
    int64_t print_time;
};

Timer timeArray()
{
    Timer timer = Timer();
    SimpleDynamicArray::SimpleDynamicArray* arr = SimpleDynamicArray::createArray(5);
    Data data1 = Data{{0.0, 0.0}, "data1"};
    Data data2 = Data{{1.0, 1.0}, "data2"};
    Data data3 = Data{{2.0, 2.0}, "data3"};
    Data data4 = Data{{3.0, 3.0}, "data4"};
    Data data5 = Data{{4.0, 4.0}, "data5"};
    Data data6 = Data{{5.0, 5.0}, "data6"};

    SimpleDynamicArray::SimpleDynamicArray* arr2 = SimpleDynamicArray::createArray(2);
    SimpleDynamicArray::push_back(arr2, Data{{0.1, 0.2f}, "newData"});
    SimpleDynamicArray::push_back(arr2, Data{{0.4, 5345345.f}, "newData1"});

    auto start = chrono::high_resolution_clock::now();
    SimpleDynamicArray::push_back(arr, data1);
    auto end = chrono::high_resolution_clock::now();
    timer.push_back_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    SimpleDynamicArray::at(arr, 0);
    end = chrono::high_resolution_clock::now();
    timer.at_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    SimpleDynamicArray::push_back(arr, data2);
    SimpleDynamicArray::push_back(arr, data3);

    start = chrono::high_resolution_clock::now();
    SimpleDynamicArray::push_front(arr, data4);
    end = chrono::high_resolution_clock::now();
    timer.push_front_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    SimpleDynamicArray::insert(arr, 1, data5);
    end = chrono::high_resolution_clock::now();
    timer.insert_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    auto newArr = SimpleDynamicArray::concatenate(arr, arr2);
    end = chrono::high_resolution_clock::now();
    timer.concatenate_time = chrono::duration_cast<TIME_TYPE>(end - start).count();
    
    start = chrono::high_resolution_clock::now();
    SimpleDynamicArray::count(arr);
    end = chrono::high_resolution_clock::now();
    timer.count_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    SimpleDynamicArray::pop_back(arr);
    end = chrono::high_resolution_clock::now();
    timer.pop_back_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    SimpleDynamicArray::pop_front(arr);
    end = chrono::high_resolution_clock::now();
    timer.pop_front_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    SimpleDynamicArray::pop_out(arr, 0);
    end = chrono::high_resolution_clock::now();
    timer.pop_out_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    SimpleDynamicArray::replace(arr, 0, data6);
    end = chrono::high_resolution_clock::now();
    timer.replace_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    SimpleDynamicArray::swap(arr, 0, 1);
    end = chrono::high_resolution_clock::now();
    timer.swap_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    SimpleDynamicArray::move(arr, 0, 1);
    end = chrono::high_resolution_clock::now();
    timer.move_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    SimpleDynamicArray::print(arr);
    end = chrono::high_resolution_clock::now();
    timer.print_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    SimpleDynamicArray::deleteArray(newArr);
    SimpleDynamicArray::deleteArray(arr);
    SimpleDynamicArray::deleteArray(arr2);

    return timer;
}

Timer timePointerArray()
{
    Timer timer = Timer();
    PointersArray::PointersArray* arr = PointersArray::createArray(5);
    Data* data1 = new Data{{0.0, 0.0}, "data1"};
    Data* data2 = new Data{{1.0, 1.0}, "data2"};
    Data* data3 = new Data{{2.0, 2.0}, "data3"};
    Data* data4 = new Data{{3.0, 3.0}, "data4"};
    Data* data5 = new Data{{4.0, 4.0}, "data5"};
    Data* data6 = new Data{{5.0, 5.0}, "data6"};

    PointersArray::PointersArray* arr2 = PointersArray::createArray(2);
    PointersArray::push_back(arr2, new Data{{0.1, 0.2f}, "newData"});
    PointersArray::push_back(arr2, new Data{{0.4, 5345345.f}, "newData1"});

    auto start = chrono::high_resolution_clock::now();
    PointersArray::push_back(arr, data1);
    auto end = chrono::high_resolution_clock::now();
    timer.push_back_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    PointersArray::at(arr, 0);
    end = chrono::high_resolution_clock::now();
    timer.at_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    PointersArray::push_back(arr, data2);
    PointersArray::push_back(arr, data3);

    start = chrono::high_resolution_clock::now();
    PointersArray::push_front(arr, data4);
    end = chrono::high_resolution_clock::now();
    timer.push_front_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    PointersArray::insert(arr, 1, data5);
    end = chrono::high_resolution_clock::now();
    timer.insert_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    auto newArr = PointersArray::concatenate(arr, arr2);
    end = chrono::high_resolution_clock::now();
    timer.concatenate_time = chrono::duration_cast<TIME_TYPE>(end - start).count();
    
    start = chrono::high_resolution_clock::now();
    PointersArray::count(arr);
    end = chrono::high_resolution_clock::now();
    timer.count_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    PointersArray::pop_back(arr);
    end = chrono::high_resolution_clock::now();
    timer.pop_back_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    PointersArray::pop_front(arr);
    end = chrono::high_resolution_clock::now();
    timer.pop_front_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    PointersArray::pop_out(arr, 0);
    end = chrono::high_resolution_clock::now();
    timer.pop_out_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    PointersArray::replace(arr, 0, data6);
    end = chrono::high_resolution_clock::now();
    timer.replace_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    PointersArray::swap(arr, 0, 1);
    end = chrono::high_resolution_clock::now();
    timer.swap_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    PointersArray::move(arr, 0, 1);
    end = chrono::high_resolution_clock::now();
    timer.move_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    PointersArray::print(arr);
    end = chrono::high_resolution_clock::now();
    timer.print_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    PointersArray::deleteArray(newArr);
    PointersArray::deleteArray(arr);
    PointersArray::deleteArray(arr2);

    return timer;
}

Timer timeList()
{
    Timer timer = Timer();
    List::List* arr = List::createList();
    Data* data1 = new Data{{0.0, 0.0}, "data1"};
    Data* data2 = new Data{{1.0, 1.0}, "data2"};
    Data* data3 = new Data{{2.0, 2.0}, "data3"};
    Data* data4 = new Data{{3.0, 3.0}, "data4"};
    Data* data5 = new Data{{4.0, 4.0}, "data5"};
    Data* data6 = new Data{{5.0, 5.0}, "data6"};

    List::List* arr2 = List::createList();
    List::push_back(arr2, new Data{{0.1, 0.2f}, "newData"});
    List::push_back(arr2, new Data{{0.4, 5345345.f}, "newData1"});

    auto start = chrono::high_resolution_clock::now();
    List::push_back(arr, data1);
    auto end = chrono::high_resolution_clock::now();
    timer.push_back_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    List::at(arr, 0);
    end = chrono::high_resolution_clock::now();
    timer.at_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    List::push_back(arr, data2);
    List::push_back(arr, data3);

    start = chrono::high_resolution_clock::now();
    List::push_front(arr, data4);
    end = chrono::high_resolution_clock::now();
    timer.push_front_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    List::insert(arr, 1, data5);
    end = chrono::high_resolution_clock::now();
    timer.insert_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    List::concatenate(arr, arr2);
    end = chrono::high_resolution_clock::now();
    timer.concatenate_time = chrono::duration_cast<TIME_TYPE>(end - start).count();
    
    start = chrono::high_resolution_clock::now();
    List::count(arr);
    end = chrono::high_resolution_clock::now();
    timer.count_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    List::pop_back(arr);
    end = chrono::high_resolution_clock::now();
    timer.pop_back_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    List::pop_front(arr);
    end = chrono::high_resolution_clock::now();
    timer.pop_front_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    List::pop_out(arr, 0);
    end = chrono::high_resolution_clock::now();
    timer.pop_out_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    List::replace(arr, 0, data6);
    end = chrono::high_resolution_clock::now();
    timer.replace_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    List::swap(arr, 0, 1);
    end = chrono::high_resolution_clock::now();
    timer.swap_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    List::move(arr, 0, 1);
    end = chrono::high_resolution_clock::now();
    timer.move_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    start = chrono::high_resolution_clock::now();
    List::print(arr);
    end = chrono::high_resolution_clock::now();
    timer.print_time = chrono::duration_cast<TIME_TYPE>(end - start).count();

    return timer;
}

int main()
{
    Timer timerArray = timeArray();
    Timer timerList = timeList();
    Timer timerPointerArray = timePointerArray();

    std::fstream file("out.txt", std::ios_base::openmode::_S_app);

    file << timerArray.at_time << ' ' << timerList.at_time << ' ' << timerPointerArray.at_time << '\n';
    file << timerArray.concatenate_time << ' ' << timerList.concatenate_time << ' ' << timerPointerArray.concatenate_time << '\n';
    file << timerArray.count_time << ' ' << timerList.count_time << ' ' << timerPointerArray.count_time << '\n';
    file << timerArray.insert_time << ' ' << timerList.insert_time << ' ' << timerPointerArray.insert_time << '\n';
    file << timerArray.move_time << ' ' << timerList.move_time << ' ' << timerPointerArray.move_time << '\n';
    file << timerArray.pop_back_time << ' ' << timerList.pop_back_time << ' ' << timerPointerArray.pop_back_time << '\n';
    file << timerArray.pop_front_time << ' ' << timerList.pop_front_time << ' ' << timerPointerArray.pop_front_time << '\n';
    file << timerArray.pop_out_time << ' ' << timerList.pop_out_time << ' ' << timerPointerArray.pop_out_time << '\n';
    file << timerArray.print_time << ' ' << timerList.print_time << ' ' << timerPointerArray.print_time << '\n';
    file << timerArray.push_back_time << ' ' << timerList.push_back_time << ' ' << timerPointerArray.push_back_time << '\n';
    file << timerArray.push_front_time << ' ' << timerList.push_front_time << ' ' << timerPointerArray.push_front_time << '\n';
    file << timerArray.replace_time << ' ' << timerList.replace_time << ' ' << timerPointerArray.replace_time << '\n';
    file << timerArray.swap_time << ' ' << timerList.swap_time << ' ' << timerPointerArray.swap_time << '\n';

    file.close();

    return 0;
}