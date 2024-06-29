#include <stdio.h>

int binarySearch(int arr[], int start, int end, int key) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            return mid; 
        }
        if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int arr[] = {3, 4, 6, -9, 10, 8, 9, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        printf("Element %d is found at position %d\n", key, result);
    } else {
        printf("Element %d is not found\n", key);
    }

    return 0;
}
