#include <iostream>
#include <cmath>

int main() {
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x, y, z;

    std::cout << "Input first point (X Y Z): ";
    std::cin >> x1 >> y1 >> z1;
    std::cout << "Input second point (X Y Z): ";
    std::cin >> x2 >> y2 >> z2;
    std::cout << "Input third point (X Y Z): ";
    std::cin >> x3 >> y3 >> z3;
    std::cout << "Input fouth point (X Y Z): ";
    std::cin >> x >> y >> z;

    double a1 = x2 - x1, b1 = y2 - y1, c1 = z2 - z1;
    double a2 = x3 - x1, b2 = y3 - y1, c2 = z3 - z1;

    double A = b1 * c2 - c1 * b2;
    double B = c1 * a2 - a1 * c2;
    double C = a1 * b2 - b1 * a2;
    double D = -(A * x1 + B * y1 + C * z1);

    double distance = abs(A * x + B * y + C * z + D) / sqrt(A * A + B * B + C * C);

    std::cout << "Answer: " << distance << std::endl;

    return 0;
}
