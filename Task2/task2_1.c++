#include <iostream>

int main() {

    printf("Please inseart x, y, z with space \n");

    float x, y, z; 

    std::cin >> x >> y >> z;

    if ((z < y) && (y < x)) {
        printf("Numbers will be:\n");
        std::cout << "x: " << x*2 << ", y: " << y*2 << ", z: " << z*2;
    } else {
        printf("Numbers will be:\n");
        std::cout << "x: " << -1*x << ", y: " << -1*y << ", z: " << -1*z;
    }

    return 0;
}