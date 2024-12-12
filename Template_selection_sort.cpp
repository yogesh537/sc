#include <iostream>
using namespace std;

// Template for selection sort
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        T temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to display the array
template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Integer array
    int intArray[] = {64, 25, 12, 22, 11};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);

    cout << "Original integer array: ";
    displayArray(intArray, intSize);

    selectionSort(intArray, intSize);

    cout << "Sorted integer array: ";
    displayArray(intArray, intSize);

    // Float array
    float floatArray[] = {64.5, 25.2, 12.1, 22.3, 11.6};
    int floatSize = sizeof(floatArray) / sizeof(floatArray[0]);

    cout << "\nOriginal float array: ";
    displayArray(floatArray, floatSize);

    selectionSort(floatArray, floatSize);

    cout << "Sorted float array: ";
    displayArray(floatArray, floatSize);

    return 0;
}
