#include <iostream>
#include <cstdlib>

int main() {

    int a, b, n;

    int * q;
    srand(time(0));

    printf("Input 3 numbers with space: ");
    std::cin >> a >> b >> n;

    q = new int[n];

    for(int i = 0; i < n; i++) {
        q[i] = a + rand() % (b - a + 1);
    }

    for (int i = 0; i < n; i++) {
        if((q[i] > q[i+1]) && (q[i] > q[i-1])) {
            std::cout << "Local max: " << q[i] << " and index of it: " << i << std::endl;
        }
    }

    return 0;
}