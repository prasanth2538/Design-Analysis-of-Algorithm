#include <stdio.h>
#include <stdlib.h>

void quickSort(int *nums, int low, int high) {
    if (low < high) {
        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (nums[j] < pivot) {
                i++;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }

        int temp = nums[i + 1];
        nums[i + 1] = nums[high];
        nums[high] = temp;

        int pi = i + 1;

        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high);
    }
}

int findMax(int *nums, int numsSize) {
    if (numsSize == 0) {
        printf("List is empty.\n");
        return -1;
    }

    quickSort(nums, 0, numsSize - 1);

    return nums[numsSize - 1];
}

int main() {
    int test1[] = {};
    int size1 = sizeof(test1) / sizeof(test1[0]);
    
    int result1 = findMax(test1, size1);
    printf("\n");

    int test2[] = {5};
    int size2 = sizeof(test2) / sizeof(test2[0]);
    
    int result2 = findMax(test2, size2);
    printf("\n");

    int test3[] = {3, 3, 3};
    int size3 = sizeof(test3) / sizeof(test3[0]);
    
    int result3 = findMax(test3, size3);

    return 0;
}
