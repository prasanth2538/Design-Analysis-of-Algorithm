#include <stdio.h>

int distinctCount(int *nums, int start, int end) {
    int count = 0;
    int freq[101] = {0};
    for (int i = start; i <= end; i++) {
        if (freq[nums[i]] == 0) {
            count++;
            freq[nums[i]] = 1;
        }
    }
    return count;
}

int sumOfSquaresOfDistinctCounts(int *nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            int count = distinctCount(nums, i, j);
            sum += count * count;
        }
    }
    return sum;
}

int main() {
    int nums[] = {1, 2, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = sumOfSquaresOfDistinctCounts(nums, numsSize);

    printf("Output: %d\n", result);

    return 0;
}
