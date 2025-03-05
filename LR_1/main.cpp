#include "sorting.h"
#include "file.h"
#include <vector>
#include <iostream>

int main() {
    int bestTime1[10], bestTime2[10], bestTime3[10];
    int worstTime1[10], worstTime2[10], worstTime3[10];
    int middleTime1[10], middleTime2[10], middleTime3[10];

    srand(time(NULL));
    
    // Массив размеров для тестирования
    std::vector<int> sizes = {500, 1000, 2000, 5000, 10000, 25000, 50000, 100000, 250000, 500000};
    
    for (int task = 1; task <= 10; task++) {
        process_array_size(sizes[task-1], task,
                         bestTime1, bestTime2, bestTime3,
                         worstTime1, worstTime2, worstTime3,
                         middleTime1, middleTime2, middleTime3);
    }

    write_to_file(bestTime1, bestTime2, bestTime3,
                 worstTime1, worstTime2, worstTime3,
                 middleTime1, middleTime2, middleTime3);
    

    std::getchar();
    return 0;
} 