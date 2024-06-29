#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    bool swapped;
    for (i = 0; i < n-1; i++) {
        swapped = false;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    bubbleSort(arr1, n1);
    printArray(arr1, n1);

    int arr2[] = {29, 10, 14, 37, 13};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    bubbleSort(arr2, n2);
    printArray(arr2, n2);

    int arr3[] = {3, 5, 2, 1, 4};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    bubbleSort(arr3, n3);
    printArray(arr3, n3);

    int arr4[] = {1, 2, 3, 4, 5};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    bubbleSort(arr4, n4);
    printArray(arr4, n4);

    int arr5[] = {5, 4, 3, 2, 1};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    bubbleSort(arr5, n5);
    printArray(arr5, n5);

    return 0;
}
