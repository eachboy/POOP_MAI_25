#include <iostream>
#include <cmath>

int main() {
    int a, b, m;

    printf("Input 3 numbers with space: ");
    std::cin >> a >> b >> m;

    for (a; a!=b; a++) {
        if (a % m == 0) {
            std::cout << a << " ";
        }
    }

    return 0;
}