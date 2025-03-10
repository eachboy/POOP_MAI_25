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

    bool isSim = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matr[i][j] != matr[j][i]) {
                isSim = false;
                break;
            }
        }
        if (!isSim) {
            break;
        }
    }

    printf("Result is: ");

    if (isSim) {
        std::cout << "Matrix is good." << std::endl;
    } else {
        std::cout << "Matrix is bad." << std::endl;
    }
}