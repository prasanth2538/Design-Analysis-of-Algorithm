#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    insertionSort(arr1, n1);
    printArray(arr1, n1);

    int arr2[] = {5, 5, 5, 5, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    insertionSort(arr2, n2);
    printArray(arr2, n2);

    int arr3[] = {2, 3, 1, 3, 2, 1, 1, 3};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    insertionSort(arr3, n3);
    printArray(arr3, n3);

    return 0;
}
