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

int* new_arr(int* arr, size_t arrSize) {
    int* newArr = new int[arrSize];
    for (int i = 0; i < arrSize; i++){
        if ((arr[i] % 2 == 0) && (i % 2 != 1)) {
            newArr[i] = arr[i];
        } else {
            newArr[i] = 0;
        }
    }
    return newArr;
}

int main() {

    int size;

    printf("Enter array size: ");
    cin >> size;

    int* arr = new int(size);

    srand(time(NULL));
    rand_arr(arr, size);
    print(arr, true, size);

    cout << "Target array: " << new_arr(arr, size) << endl;
    
    print(new_arr(arr, size), false, size);

    return 0;
}