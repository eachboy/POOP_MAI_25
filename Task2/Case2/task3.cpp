#include <iostream>
#include <algorithm>

using namespace std;

struct Triangle {
    double a;
    double b;
    double c;
};

Triangle inputData() {
    Triangle triangle;
    printf("Enter triangle data (a, b, c): ");
    cin >> triangle.a >> triangle.b >> triangle.c;
    return triangle;
}

bool triangle(const Triangle &t) {
    if (t.a + t.b > t.c && t.a + t.c > t.b && t.b + t.c > t.a) return true;
    else return false;
}

bool pyramid(const Triangle &t1, const Triangle &t2, const Triangle &t3) {
    if (!triangle(t1) || !triangle(t2) || !triangle(t3)) {
        return false;
    }

    double edges[9] = {t1.a, t1.b, t1.c, t2.a, t2.b, t2.c, t3.a, t3.b, t3.c};
    
    sort(edges, edges + 9);
    
    Triangle longest = {edges[6], edges[7], edges[8]};
    
    if (triangle(longest)) {
        return false;
    }
    
    return true;
}

int main() {
    Triangle t1 = inputData();
    Triangle t2 = inputData();
    Triangle t3 = inputData();

    if (pyramid(t1, t2, t3)) printf("Triangle is possible\n");
    else printf("Triangle is not possible\n");

    return 0;
}