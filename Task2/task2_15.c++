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

    std::cout << "\nGenerated matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matr[i][j] << "\t";
        }    
        std::cout << "\n";
    }

    std::cout << "\n\nResult data:\n";

    for (int i = 0; i<n; i++) {
        int mx = -9999;
        int mn = 9999;
        for (int j = 0; j<m; j++) {
            if (matr[i][j] < mn) {
                mn = matr[i][j];
            }
            if (matr[i][j] > mx) {
                mx = matr[i][j];
            }
        }
        std::cout << "Min numder: " << mn << " Max number: " << mx << "\n";
        
    }
    return 0;
}