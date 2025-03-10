#include <iostream>

using namespace std;

void rand_arr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void print(int* arr, int n) {
    printf("Generated array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
} 

int* getMaxElem(int* arr, size_t SizeArr) {
    int max = arr[0];
    int* maxTarget = &arr[0];
    for (int i = 0; i < SizeArr; i++) {
        if (arr[i] > arr[0]) {
            max = arr[i];
            maxTarget = &arr[i];
        }
    }
    printf("\t Max elem: %i \n", max);
    printf("\t Max target: ");
    return maxTarget;
}

int main() {
    int size;

    printf("Enter array size: ");
    cin >> size;

    int* arr = new int[size];

    srand(time(NULL));
    rand_arr(arr, size);
    print(arr, size);

    cout << "Info: " << getMaxElem(arr, size);

    return 0;
}