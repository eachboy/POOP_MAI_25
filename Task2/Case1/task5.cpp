#include <iostream>
#include <string>

using namespace std;

int main() {

    string line1;
    string line2;
    string line3;

    printf("Enter line1: ");
    cin >> line1;
    printf("Enter line2: ");
    cin >> line2;

    line3 = line1 + line2;
    cout << line3;

    return 0;
}