#include <iostream>

int main() {

    int x1, y1, x2, y2;
    int f1;

    printf("Please input your coordinates (1-8): ");
    std::cin >> x1 >> y1;

    printf("Please pick your figure (1) rook, 2) bishop, 3) queen, 4) knight): ");
    std::cin >> f1;

    printf("=====\n");
    printf("Please input enemy coordinates (1-8): ");
    std::cin >> x2 >> y2;

    if ((x1 < 1) || (x2 < 1) || (y1 < 1) || (y2 < 1) || (x1 > 8) || (x2 > 8) || (y1 > 8) || (y2 > 8) || ((x1 == x2) && (y1 == y2))) {
        printf("Invalid input");
        return 0;
    }

    if (f1 == 1) {
        if ((x1 == x2 && y1 != y2) ||  (x1 != x2 && y1 == y2))  {
            printf("You can catch the enemy.");
        } else {
            printf("You can't catch the enemy.");
        }
    } else if (f1 == 2) {
        if (abs(x1 - x2) == abs(y1 - y2)) {
            printf("You can catch the enemy.");
        } else {
            printf("You can't catch the enemy.");
        }
    } else if (f1 == 3) {
        if ((x1 == x2 && y1 != y2) ||  (x1 != x2 && y1 == y2) || (abs(x1 - x2) == abs(y1 - y2))) {
            printf("You can catch the enemy.");
        } else {
            printf("You can't catch the enemy.");
        }
    } else if (f1 == 4) {
        if (((x1 + 3) && (y1 - 1)) || ((x1 + 3) && (y1 + 1)) || ((x1 - 3) && (y1 - 1)) || ((x1 - 3) && (y1 + 1)) || ((x1 - 1) && (y1 - 3)) || ((x1 + 1) && (y1 - 3)) ||((x1 - 1) && (y1 + 3)) || ((x1 + 1) && (y1 + 3))) {
            printf("You can catch the enemy.");
        } else {
            printf("You can't catch the enemy.");
        }
    }


    return 0;
}