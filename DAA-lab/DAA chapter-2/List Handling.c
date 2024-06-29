#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr1[] = {};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printArray(arr1, size1);

    int arr2[] = {1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printArray(arr2, size2);

    int arr3[] = {7, 7, 7, 7};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printArray(arr3, size3);

    int arr4[] = {-5, -1, -3, -2, -4};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    sortArray(arr4, size4);
    printArray(arr4, size4);

    return 0;
}
