#include <iostream>

using namespace std;

void rand_arr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void print(int* arr, bool type, int n) {
    if (type) printf("Generated array: ");
    else printf("Finish array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {

    int n;

    cout << "Enter N: ";
    cin >> n;

    int* arr = new int[n];

    srand(time(NULL));

    rand_arr(arr, n);
    print(arr, true, n);

    int* arr1 = new int[n*2];

    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
        arr1[i + n] = arr[i];
    }

    print(arr1, false, n*2);

    return 0;
}