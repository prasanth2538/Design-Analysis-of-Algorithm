#include <stdio.h>

int findMax(int *nums, int numsSize) {
    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

int main() {
    int test1[] = {1, 2, 3, 4, 5};
    int test2[] = {7, 7, 7, 7, 7};
    int test3[] = {-10, 2, 3, -4, 5};
    int size1 = sizeof(test1) / sizeof(test1[0]);
    int size2 = sizeof(test2) / sizeof(test2[0]);
    int size3 = sizeof(test3) / sizeof(test3[0]);

    int result1 = findMax(test1, size1);
    int result2 = findMax(test2, size2);
    int result3 = findMax(test3, size3);

    printf("Output for Test Case 1: %d\n", result1);
    printf("Output for Test Case 2: %d\n", result2);
    printf("Output for Test Case 3: %d\n", result3);

    return 0;
}
