#include <iostream>

using namespace std;

void rand_arr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void change(int* arr, int index) {
    int* ptr = arr;
    ptr += index;
    *ptr = 0;
}

void print(int* arr, bool type, int n) {
    if (type) printf("Generated array: ");
    else printf("Finish array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(){

    int n;

    cout << "Enter N: ";
    cin >> n;

    int arr[n];

    srand(time(0));
    rand_arr(arr, n);
    print(arr, true, n);

    for (int i = 1; i < n; i+=2) change(arr, i);

    print(arr, false, n);

    return 0;
}