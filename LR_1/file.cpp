#include "file.h"
#include <fstream>
#include <iostream>

void write_to_file(int* bestTime1, int* bestTime2, int* bestTime3,
                  int* worstTime1, int* worstTime2, int* worstTime3,
                  int* middleTime1, int* middleTime2, int* middleTime3) {
    std::ofstream outFile("time_data.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < 10; i++) outFile << bestTime1[i] << " ";
        outFile << std::endl;
        
        for (int i = 0; i < 10; i++) outFile << bestTime2[i] << " ";
        outFile << std::endl;
        
        for (int i = 0; i < 10; i++) outFile << bestTime3[i] << " ";
        outFile << std::endl;
        
        for (int i = 0; i < 10; i++) outFile << worstTime1[i] << " ";
        outFile << std::endl;
        
        for (int i = 0; i < 10; i++) outFile << worstTime2[i] << " ";
        outFile << std::endl;
        
        for (int i = 0; i < 10; i++) outFile << worstTime3[i] << " ";
        outFile << std::endl;
        
        for (int i = 0; i < 10; i++) outFile << middleTime1[i] << " ";
        outFile << std::endl;
        
        for (int i = 0; i < 10; i++) outFile << middleTime2[i] << " ";
        outFile << std::endl;
        
        for (int i = 0; i < 10; i++) outFile << middleTime3[i] << " ";
        outFile << std::endl;
        
        std::cout << "File saved" << std::endl;
        outFile.close();
    } else {
        std::cout << "Ошибка открытия файла для записи" << std::endl;
    }
}