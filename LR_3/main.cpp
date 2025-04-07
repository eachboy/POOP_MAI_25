#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include <map>
#include <fstream>
#include <iomanip>

#define n 5

using namespace std;

// Вспомогательные функции
double* GenRavArr(int size, double a, double b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(a, b);
    
    double* array = new double[size];

    for(int i = 0; i < size; i++) {
        array[i] = dis(gen);
    }
    return array;
}

double* GenNormArr(int size, double u, double o)
{
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> dis(u, o);
    
    double* array = new double[size];

    for(int i = 0; i < size; i++) {
        array[i] = dis(gen);
    }
    return array;
}

void ArrayPrint(double* array, int size)
{
    cout << "\n=== Generated Array ===\n";
    for (int i = 0; i < size; i++) {
        cout << fixed << setprecision(4) << setw(10) << array[i];
        if ((i + 1) % 5 == 0) cout << endl;  // Новая строка каждые 5 чисел
    }
    cout << "\n====================\n";
}

int PrintInfo()
{   
    int type;
    cout << "\n\n\t\t MENU PROGRAM \n";
    cout << "============================================\n";
    cout << "1. Generate array (uniform distribution)\n";
    cout << "2. Generate array (normal distribution)\n";
    cout << "3. Generate container (uniform: a=0, b=n*1000)\n";
    cout << "4. Generate container (normal: u=N*1000/2, o=N*500/2)\n";
    cout << "5. Calculate mean and standard deviation\n";
    cout << "6. Estimate distribution parameters\n";
    cout << "7. Create histogram\n";
    cout << "0. Exit program\n";
    cout << "============================================\n";
    cout << "Your choice: ";
    cin >> type;
    cout << "\n";
    return type;
}

// Глобальные переменные для хранения текущего массива
double* current_array = nullptr;
int current_size = 0;

// Основные функции
double* fill_cont_ravn(int size, double a, double b)
{   
    // Освобождаем предыдущий массив, если он существует
    if (current_array != nullptr) {
        delete[] current_array;
    }
    
    current_array = GenRavArr(size, a, b);
    current_size = size;
    ArrayPrint(current_array, size);
    return current_array;
}

double* fill_cont_norm(int size, double u, double o)
{   
    if (current_array != nullptr) {
        delete[] current_array;
    }
    
    current_array = GenNormArr(size, u, o);
    current_size = size;
    ArrayPrint(current_array, size);
    return current_array;
}

double calculateMean(double* array, int size) 
{
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

double calculateStdDev(double* array, int size, double mean) 
{
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += pow(array[i] - mean, 2);
    }
    return sqrt(sum / size);
}

void estimateParameters(double* array, int size) 
{
    double sample_mean = calculateMean(array, size);
    double sample_stddev = calculateStdDev(array, size, sample_mean);
    double standard_error = sample_stddev / sqrt(size);
    double confidence_interval = 1.96 * standard_error;
    
    cout << "\n=== Distribution Parameters Estimation ===\n";
    cout << setfill('-') << setw(45) << "\n";
    cout << setfill(' ');
    cout << left << setw(35) << "Sample mean: " 
         << right << setw(10) << fixed << setprecision(4) << sample_mean << endl;
    cout << left << setw(35) << "Sample standard deviation: " 
         << right << setw(10) << sample_stddev << endl;
    cout << left << setw(35) << "Standard error of mean: " 
         << right << setw(10) << standard_error << endl;
    cout << "\n95% Confidence interval for mean:\n";
    cout << "[" << setw(10) << sample_mean - confidence_interval << " ; " 
         << setw(10) << sample_mean + confidence_interval << "]\n";
    cout << setfill('-') << setw(45) << "\n" << setfill(' ');
}

void createHistogram(double* array, int size) 
{
    // Находим минимальное и максимальное значения
    double min_val = array[0];
    double max_val = array[0];
    for(int i = 1; i < size; i++) {
        if(array[i] < min_val) min_val = array[i];
        if(array[i] > max_val) max_val = array[i];
    }
    
    // Определяем количество интервалов (bins) по формуле Стёрджеса
    int num_bins = 1 + 3.322 * log10(size);
    
    // Вычисляем ширину интервала
    double bin_width = (max_val - min_val) / num_bins;
    
    // Создаем map для хранения частот
    map<int, int> histogram;
    
    // Заполняем гистограмму
    for(int i = 0; i < size; i++) {
        int bin = (array[i] - min_val) / bin_width;
        histogram[bin]++;
    }
    
    cout << "\n=== Histogram Analysis ===\n";
    cout << setfill('-') << setw(50) << "\n" << setfill(' ');
    cout << left << setw(25) << "Number of intervals: " << num_bins << endl;
    cout << left << setw(25) << "Interval width: " 
         << fixed << setprecision(2) << bin_width << endl;
    cout << "Value range: [" << min_val << ", " << max_val << "]\n";
    
    cout << "\n=== Frequency Distribution ===\n";
    cout << setfill('-') << setw(65) << "\n" << setfill(' ') << endl;
    for(const auto& pair : histogram) {
        double interval_start = min_val + pair.first * bin_width;
        double interval_end = interval_start + bin_width;
        
        // Форматированный вывод интервала и частоты
        cout << "[" << setw(8) << interval_start << " - " 
             << setw(8) << interval_end << "] ";
        cout << setw(5) << pair.second << " | ";
        
        // Графическое представление
        int stars = pair.second * 50 / size;
        for(int i = 0; i < stars; i++) cout << "*";
        cout << endl;
    }
    cout << setfill('-') << setw(65) << "\n" << setfill(' ');
    
    // Сохранение в файл
    ofstream outFile("histogram_data.csv");
    if(!outFile) {
        cout << "\nError: Cannot open file!\n";
        return;
    }
    
    outFile << "Interval;Frequency;Relative frequency\n";
    for(const auto& pair : histogram) {
        double interval_start = min_val + pair.first * bin_width;
        double interval_end = interval_start + bin_width;
        double relative_freq = static_cast<double>(pair.second) / size;
        
        outFile << fixed << setprecision(2)
               << interval_start << " - " << interval_end << ";"
               << pair.second << ";"
               << relative_freq << endl;
    }
    
    outFile.close();
    cout << "\nHistogram data saved to 'histogram_data.csv'\n";
}

// Главная функция
int main() 
{   
    bool flag = false;
    int size;
    double a, b, u, o;
    double mean, stddev;

    int type = PrintInfo();  

    switch (type)
    {
    case 1:
        cout << "Enter numbers (int double double): ";
        cin >> size >> a >> b;
        fill_cont_ravn(size, a, b);
        break;

    case 2:
        cout << "Enter numbers (int double double): ";
        cin >> size >> u >> o;
        fill_cont_ravn(size, u, o);
        break;

    case 3:
        a = 0;
        b = n * 100;
        cout << "Enter size (int): ";
        cin >> size;
        fill_cont_ravn(size, a, b);
        break;

    case 4:
        u = (n * 100) / 2;
        o = (n * 50) / 2;
        cout << "Enter size (int): ";
        cin >> size;
        fill_cont_norm(size, u, o);
        break;

    case 5:
        if (current_array == nullptr) {
            cout << "\n=== ERROR ===\n";
            cout << "Please generate array data first (use option 3 or 4)!\n";
            cout << "============\n";
            break;
        }
        mean = calculateMean(current_array, current_size);
        stddev = calculateStdDev(current_array, current_size, mean);
        
        cout << "Mathematical expectation: \t" << mean << endl;
        cout << "Standard deviation: \t" << stddev << endl;
        break;

    case 6:
        if (current_array == nullptr) {
            cout << "\n=== ERROR ===\n";
            cout << "Please generate array data first (use option 3 or 4)!\n";
            cout << "============\n";
            break;
        }
        estimateParameters(current_array, current_size);
        break;

    case 7:
        if (current_array == nullptr) {
            cout << "\n=== ERROR ===\n";
            cout << "Please generate array data first (use option 3 or 4)!\n";
            cout << "============\n";
            break;
        }
        createHistogram(current_array, current_size);
        break;
    
    default:
        cout << "\n\n\tProgram closing...";
        flag = true;
        break;
    }

    if (flag) {
        if (current_array != nullptr) {
            delete[] current_array;
            current_array = nullptr;
        }
        return 0;
    }
    else main();
}