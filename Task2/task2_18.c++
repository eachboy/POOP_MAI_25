#include <iostream>
#include <cmath>

int main() {

    const int n = 4;
    int a, b;
    srand(time(0));

    printf("Input A and B with space: ");
    std::cin >> a >> b;

    int matr[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matr[i][j] = a + rand() % (b - a + 1);
        }
    }

    printf("\nGenerated matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matr[i][j] << "\t";
        }    
        std::cout << "\n";
    }

    int num;
    std::cout << "Enter line (1 - " << n << "): ";
    std::cin >> num;

    printf("\nAnswer is:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (num-1 == i) {
                matr[i][j] = 0;
                std::cout << matr[i][j] << "\t";
            } else {
                std::cout << matr[i][j] << "\t";
            }
        }    
        std::cout << "\n";
    }

}