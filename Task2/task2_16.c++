#include <iostream>
#include <cmath>

int main() {

    const int n = 3;
    const int m = 3;
    int a, b;
    srand(time(0));

    printf("Input A and B with space: ");
    std::cin >> a >> b;

    int matr[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matr[i][j] = a + rand() % (b - a + 1);
        }
    }

    printf("\nGenerated matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matr[i][j] << "\t";
        }    
        std::cout << "\n";
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(abs(i) != abs(j)) {
                matr[i][j] = 1;
            }
        }
    }

    printf("\nGenerated matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matr[i][j] << "\t";
        }    
        std::cout << "\n";
    }
    return 0;
}