#include "sorting.h"
#include <ctime>
#include <iomanip>

void sortN2(int* arr, int n) {
    int i, j, num;
    for (i = 1; i < n; i++) {
        num = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > num) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = num;
    }
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pivot = arr[(low + high) / 2];
        int i = low;
        int j = high;
        
        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        
        if (low < j)
            quickSort(arr, low, j);
        if (i < high)
            quickSort(arr, i, high);
    }
}

void generate(int* arr, int* arr1, int* arr2, int size, int minValue, int maxValue) {
    
    for (int i = 0; i < size; i++) {
        arr[i] = minValue + rand() % (maxValue - minValue + 1);
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }
}

int sec_time(int* arr, int n, int type) {
    int* tempArr = new int[n];
    std::copy(arr, arr + n, tempArr);
    
    auto sTime = std::chrono::high_resolution_clock::now();
    
    switch (type) {
        case 1:
            sortN2(tempArr, n);
            break;
        case 2:
            quickSort(tempArr, 0, n-1);
            break;
        case 3:
            std::sort(tempArr, tempArr + n);
            break;
    }
    
    auto eTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(eTime - sTime);
    
    delete[] tempArr;
    return duration.count();
}

int best_time(int* arr, int n, int type) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;  // Заполняем по возрастанию
    }
    return sec_time(arr, n, type);
}

int worst_time(int* arr, int n, int type) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i - 1;  // Заполняем в обратном порядке
    }
    return sec_time(arr, n, type);
}

float middle_time(int* arr) {
    int middleTime = 0;
    for (int i = 0; i < 10; i++) {
        middleTime += arr[i];
    }
    return middleTime/10.0f;
}

void process_array_size(int n, int task,
                       int* bestTime1, int* bestTime2, int* bestTime3,
                       int* worstTime1, int* worstTime2, int* worstTime3,
                       int* middleTime1, int* middleTime2, int* middleTime3) {
    time_t now;
    char timeString[26];
    time(&now);
    ctime_s(timeString, sizeof(timeString), &now);
    timeString[24] = '\0';

    std::cout << "\n===========" << std::endl;
    std::cout << "Task " << task << " started at: " << timeString << std::endl;
    std::cout << "Array size: " << n << std::endl;
    std::cout << "-------------" << std::endl;

    int* arr = new int[n];
    int* arr1 = new int[n];
    int* arr2 = new int[n];
    int* bestArr = new int[n];
    int* worstArr = new int[n];

    int TimeArr[10];
    int TimeArr1[10];
    int TimeArr2[10];

    std::cout << "\nTesting average cases:" << std::endl;
    std::cout << "Progress: ";
    for (int j = 0; j < 10; j++) {
        generate(arr, arr1, arr2, n, 0, n);
        TimeArr[j] = sec_time(arr, n, 1);  // O(n2)
        TimeArr1[j] = sec_time(arr1, n, 2); // O(nlg(n))
        TimeArr2[j] = sec_time(arr2, n, 3); // std::sort
        std::cout << j + 1 << "0% ";
    }

    std::cout << std::endl;
    std::cout << "Data calculation. Wait for it..." << std::endl;


    middleTime1[task-1] = middle_time(TimeArr);
    middleTime2[task-1] = middle_time(TimeArr1);
    middleTime3[task-1] = middle_time(TimeArr2);
    std::cout << "The data is calculated. Calculating the best case..." << std::endl;

    // Измеряем лучший случай
    bestTime1[task-1] = best_time(bestArr, n, 1);
    bestTime2[task-1] = best_time(bestArr, n, 2);
    bestTime3[task-1] = best_time(bestArr, n, 3);
    std::cout << "The best case has been calculated. Calculating the worst case..." << std::endl;
    
    // Измеряем худший случай
    worstTime1[task-1] = worst_time(worstArr, n, 1);
    worstTime2[task-1] = worst_time(worstArr, n, 2);
    worstTime3[task-1] = worst_time(worstArr, n, 3);
    std::cout << "The worst case has been calculated. Output of results:" << std::endl;

    time(&now);
    ctime_s(timeString, sizeof(timeString), &now);
    timeString[24] = '\0';
    
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "                     Time Results (microseconds)               " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "Algorithm      |    Best Case    |   Average Case  |  Worst Case" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Insertion Sort |  " << std::setw(13) << bestTime1[task-1] 
              << " |  " << std::setw(13) << middleTime1[task-1] 
              << " |  " << std::setw(10) << worstTime1[task-1] << std::endl;
    std::cout << "Quick Sort     |  " << std::setw(13) << bestTime2[task-1] 
              << " |  " << std::setw(13) << middleTime2[task-1] 
              << " |  " << std::setw(10) << worstTime2[task-1] << std::endl;
    std::cout << "std::sort      |  " << std::setw(13) << bestTime3[task-1] 
              << " |  " << std::setw(13) << middleTime3[task-1] 
              << " |  " << std::setw(10) << worstTime3[task-1] << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "Task " << task << " completed at: " << timeString << std::endl;
    std::cout << "===========\n\n\n\n" << std::endl;

    // Освобождаем память
    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] bestArr;
    delete[] worstArr;
}