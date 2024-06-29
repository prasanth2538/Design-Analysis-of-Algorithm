#include <stdio.h>

int findKthPositive(int arr[], int size, int k) {
    int missingCount = 0;
    int currentNum = 1;
    int i = 0;

    while (missingCount < k) {
        if (i < size && arr[i] == currentNum) {
            i++;
        } else {
            missingCount++;
            if (missingCount == k) {
                return currentNum;
            }
        }
        currentNum++;
    }

    return currentNum;
}

int main() {
    int arr1[] = {2, 3, 4, 7, 11};
    int k1 = 5;
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Output: %d\n", findKthPositive(arr1, size1, k1));

    int arr2[] = {1, 2, 3, 4};
    int k2 = 2;
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Output: %d\n", findKthPositive(arr2, size2, k2));

    return 0;
}
