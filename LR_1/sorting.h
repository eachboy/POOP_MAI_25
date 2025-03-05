#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <algorithm>
#include <chrono>

void sortN2(int* arr, int n);
void quickSort(int* arr, int low, int high);
void generate(int* arr, int* arr1, int* arr2, int size, int minValue, int maxValue);
int sec_time(int* arr, int n, int type);
int best_time(int* bestArr, int n, int type);
int worst_time(int* arr, int n, int type);
float middle_time(int* arr);

// ... существующий код ...
void process_array_size(int n, int task,
                       int* bestTime1, int* bestTime2, int* bestTime3,
                       int* worstTime1, int* worstTime2, int* worstTime3,
                       int* middleTime1, int* middleTime2, int* middleTime3);
                       
#endif