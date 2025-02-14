#include <iostream>
#include <cstdlib>

int main() {

    int a, b, n, mx, imx;
    mx = -1;

    int * q;
    srand(time(0));

    printf("Input 3 numbers with space: ");
    std::cin >> a >> b >> n;

    q = new int[n];

    for(int i = 0; i < n; i++) {
        q[i] = a + rand() % (b - a + 1);
    }

    for (int i = 0; i < n; i++) {
        if (mx < q[i]) {
            mx = q[i];
            imx = i;
        }
    }

    std::cout << "Global max: " << mx << " and index of it: " << imx;

    return 0;
}