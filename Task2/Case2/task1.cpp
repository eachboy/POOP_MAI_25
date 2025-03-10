#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
    double z;
};

Point inputPoint(int type) {
    Point point;
    printf("Enter coordinates for %i point: ", type);
    cin >> point.x >> point.y >> point.z;
    return point;
}

double distance(const Point& a, const Point& b) {
    double dist_x = b.x - a.x;
    double dist_y = b.y - a.y;
    double dist_z = b.z - a.z;

    return sqrt(dist_x*dist_x + dist_y*dist_y + dist_z*dist_z);
}

int main() {

    Point A = inputPoint(1);
    Point B = inputPoint(2);

    cout << "Distance between points: " << distance(A, B);

    return 0;
}