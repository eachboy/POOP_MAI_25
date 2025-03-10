#include <iostream>

using namespace std;

struct Rectangle {
    double wigth;
    double height;
};

Rectangle inputRectangle() {
    Rectangle rectangle;
    printf("Enter rectangle data (wigth, height): ");
    cin >> rectangle.wigth >> rectangle.height;
    return rectangle;
}

double Square(const Rectangle& a) {
    return a.wigth * a.height;
}

int main() {

    Rectangle rectangle = inputRectangle();

    printf("Square: ");
    cout << Square(rectangle);

    return 0;
}