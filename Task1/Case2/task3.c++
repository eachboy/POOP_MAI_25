#include <iostream>

int main() {

    int a, b;
    float n, m, x;

    printf("Select weight type input: \n");
    printf("1 – kilogram, 2 – milligram, 3 – gram, 4 – ton, 5 – hundredweight\n");
    std::cin >> a; 

    printf("Select weight type you want: \n");
    printf("1 – kilogram, 2 – milligram, 3 – gram, 4 – ton, 5 – hundredweight\n");
    std::cin >> b; 

    printf("Input weigth: ");
    std::cin >> m;

    switch (a)
    {
    case 1:
        n = m;
        break;
    
    case 2:
        n =  m*1e-6;
        break;

    case 3:
        n =  m*1e-3;
        break;

    case 4:
        n =  m*1e3;
        break;

    case 5:
        n =  m*1e2;
        break;

    default:
        printf("Incorect statement");
        break;
    };

    switch (b)
    {
    case 1:
        std::cout << "Answer: " << m;
        break;

    case 2:
        std::cout << "Answer: " << m*1e6;
        break;

    case 3:
        std::cout << "Answer: " << m*1e3;
        break;

    case 4:
        std::cout << "Answer: " << m*1e-3;
        break;

    case 5:
        std::cout << "Answer: " << m*1e-2;
        break;
    
    default:
        printf("Incorect statement");
        break;
    };

    return 0;
}