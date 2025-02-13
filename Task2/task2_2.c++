#include <iostream>
using namespace std;

int main() {
    int n;
    float m;

    printf("Select weight type: \n");
    printf("1 – kilogram, 2 – milligram, 3 – gram, 4 – ton, 5 – hundredweight\n");

    std::cin >> n; 

    printf("Select weight: ");

    std::cin >> m;

    switch (n)
    {
    case 1:
        std::cout << "Answer: " << m;
        break;
    
    case 2:
        std::cout << "Answer: " << m*1e-6;
        break;

    case 3:
        std::cout << "Answer: " << m*1e-3;
        break;

    case 4:
        std::cout << "Answer: " << m*1e3;
        break;

    case 5:
        std::cout << "Answer: " << m*100;
        break;

    default:
        printf("Incorect statement");
        break;
    }

    return 0;
}