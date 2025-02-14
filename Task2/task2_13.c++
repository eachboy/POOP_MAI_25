#include <iostream>
#include <cstdlib>

int main() {

    int a, b, n;
    int i = 0;
    int * list1;
    int * list2;
    srand(time(0));

    printf("Input 3 numbers with space: ");
    std::cin >> a >> b >> n;

    list1 = new int[n];
    list2 = new int[n];

    printf("Generated numders: ");

    for (i; i<n; i++) {
        list1[i] = a + rand() % (b - a + 1);
        std::cout << list1[i] << " ";
        list2[n-i-1] = list1[i];
    }

    printf("\nReversed numders: ");

    for (i = 0; i<n; i++) {
        std::cout << list2[i] << " ";
    }
    
    return 0;
}