#include <stdio.h>

int countPairs(int *nums, int numsSize, int k) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j] && (i * j) % k == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int nums[] = {3, 1, 2, 2, 2, 1, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    int result = countPairs(nums, numsSize, k);

    printf("Output: %d\n", result);

    return 0;
}
