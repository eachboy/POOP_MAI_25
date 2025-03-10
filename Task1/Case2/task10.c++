#include <iostream>
#include <cstdlib>

int main() {

    int a, b, n, k, num, sum;

    k = 0;
    sum = 0;
    srand(time(0));

    printf("Input 3 numbers with space: ");
    std::cin >> a >> b >> n;
    
    printf("Numbers: ");
    for (int i; i<n; i++) {
        num = a + rand() % (b - a + 1);
        std::cout << num << " ";
        if ((num%2==0) && (i%2==0)) {
            k += 1;
            sum += num;
        }
    }

    std::cout << "\nSr_Ar: " << sum/k;

    return 0;
}