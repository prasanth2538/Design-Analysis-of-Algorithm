#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {5, 2, 9, 1, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    selectionSort(arr1, n1);
    printArray(arr1, n1);

    int arr2[] = {10, 8, 6, 4, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    selectionSort(arr2, n2);
    printArray(arr2, n2);

    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    selectionSort(arr3, n3);
    printArray(arr3, n3);

    return 0;
}
