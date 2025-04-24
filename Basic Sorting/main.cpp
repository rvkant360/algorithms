#include <iostream>
#include <vector>
#include <climits>

// O(n^2)
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size -1; i++) {
        for (int j = 0; j < size -1 -i; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

// O(n^2)
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int smallest = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[smallest]) {
                smallest = j;
            }
        }
        std::swap(arr[i], arr[smallest]);
    }
}

// O(n^2)
void insertionSort(int arr[], int size) {
     for (int i = 1; i < size; i++) {
        int curr = arr[i]; // Element to be inserted
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr; // Insert curr at the correct position
     }
}

int main() {

    int arr[5] = {1,4,5,2,3};
    insertionSort(arr, 5);

    for(int a : arr) {
        std::cout << a << std::endl;
    }

    return 0;
}
