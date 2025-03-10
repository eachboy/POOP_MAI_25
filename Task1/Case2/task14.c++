#include <iostream>
#include <cstdlib>

int main() {

    int a, b, n, num;
    int i = 0;
    int * list;
    srand(time(0));

    printf("Input 3 numbers with space: ");
    std::cin >> a >> b >> n;

    list = new int[n];

    printf("Generated numders: ");

    for (i; i<n; i++) {
        list[i] = a + rand() % (b - a + 1);
        std::cout << list[i] << " ";
    }

    printf("\nReversed numders: ");

    for (i = 0; i < n/2; i++) {
        num = list[i];
        list[i] = list[n - i - 1];
        list[n - i - 1] = num;
    }

    for (i = 0; i < n; i++) {
        std::cout << list[i] << " ";
    }
    
    return 0;
}