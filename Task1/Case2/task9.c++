#include <iostream>
#include <cmath>

int main() {
    int n, k;

    k = 0;

    printf("Write one number: ");
    std::cin >> n;

    for (int i = 2; i < 500; ++i) {

        bool isPrime = true;

        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime && k<n){ 
            std::cout << i << " ";
            k += 1; 
        }
            
    }
    return 0;

}