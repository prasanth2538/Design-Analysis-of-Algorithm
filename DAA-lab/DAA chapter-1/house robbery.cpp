#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int robHelper(int* nums, int start, int end) {
    int prevMax = 0;
    int currMax = 0;

    for (int i = start; i <= end; i++) {
        int temp = currMax;
        currMax = max(currMax, prevMax + nums[i]);
        prevMax = temp;
    }

    return currMax;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }

    return max(robHelper(nums, 0, numsSize - 2), robHelper(nums, 1, numsSize - 1));
}

int main() {
    int nums1[] = {2, 3, 2};
    int numsSize1 = 3;

    int nums2[] = {1, 2, 3, 1};
    int numsSize2 = 4;

    printf("Output 1: %d\n", rob(nums1, numsSize1));
    printf("Output 2: %d\n", rob(nums2, numsSize2));

    return 0;
}
