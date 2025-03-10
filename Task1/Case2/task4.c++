#include <iostream>
#include <cmath>

int main() {

    float a, b, c, d;

    printf("Input rations: \n");
    std::cin >> a >> b >> c;

    d = b*b - 4*a*c;

    if (d > 0) {
        std::cout << "There are 2 roots: " << ((-b - sqrt(d))/(2*a)) << " and " << ((-b + sqrt(d))/(2*a));
    } else if (d == 0) {
        std::cout << "There is 1 root: " << (-b)/(2*a);
    } else {
        std::cout << "There are no roots";
    }

    return 0;
}